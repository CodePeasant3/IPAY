#include "mp3player.h"
#include <QDebug>
#include <QFile>
#include <iostream>

MP3Player::MP3Player(QObject *parent) : QObject(parent),
    m_player(new QMediaPlayer(this)),
    m_pendingLoads(0),
    m_allLoadsSuccessful(true)
{
    connect(m_player, &QMediaPlayer::mediaStatusChanged, this, &MP3Player::onMediaStatusChanged);
    connect(m_player, SIGNAL(error(QMediaPlayer::Error)), this, SLOT(onErrorOccurred(QMediaPlayer::Error)));
    connect(m_player, &QMediaPlayer::stateChanged, this, &MP3Player::stateChanged);

    // 默认音量
    m_player->setVolume(100); // 75% 音量

    this->preloadMultiple({
                      {"1", "Resources/audio/pay_success.mp3"},
                      {"2", "Resources/audio/pay_failed.mp3"},
                      {"3", "Resources/audio/refund_success.mp3"}});
}

MP3Player::~MP3Player()
{
    stop();
    unloadAll();
}

bool MP3Player::preload(const QString &id, const QString &filePath)
{
    if (m_loadedFiles.contains(id)) {
        qDebug() << "文件已加载:" << id;
        emit fileLoaded(id, true);
        return true;
    }

    if (!QFile::exists(filePath)) {
        qDebug() << "文件不存在:" << filePath;
        emit error(id, "文件不存在");
        emit fileLoaded(id, false);
        return false;
    }

    QUrl url = QUrl::fromLocalFile(filePath);
    QMediaContent content(url);

    m_loadedFiles[id] = content;
    m_pendingLoads++;

    // 如果当前没有播放内容，使用player预加载
    if (m_player->mediaStatus() == QMediaPlayer::NoMedia) {
        m_player->setMedia(content);
    }

    return true;
}

bool MP3Player::preloadMultiple(const QMap<QString, QString> &idFilePathMap)
{
    if (idFilePathMap.isEmpty()) {
        emit allLoaded(true);
        return true;
    }

    m_pendingLoads = 0;
    m_allLoadsSuccessful = true;

    for (auto it = idFilePathMap.begin(); it != idFilePathMap.end(); ++it) {
        preload(it.key(), it.value());
    }

    return m_pendingLoads > 0;
}

bool MP3Player::isLoaded(const QString &id) const
{
    return m_loadedFiles.contains(id);
}

void MP3Player::unload(const QString &id)
{
    if (m_currentId == id) {
        stop();
    }

    m_loadedFiles.remove(id);
    m_loadErrors.remove(id);
}

void MP3Player::unloadAll()
{
    stop();
    m_loadedFiles.clear();
    m_loadErrors.clear();
}

bool MP3Player::play(const QString &id)
{
    if (!m_loadedFiles.contains(id)) {
        qDebug() << "文件未加载:" << id;
        emit error(id, "文件未加载");
        return false;
    }

    if (m_loadErrors.contains(id)) {
        qDebug() << "文件加载失败:" << id;
        emit error(id, "文件加载失败");
        return false;
    }

    m_currentId = id;
    m_player->setMedia(m_loadedFiles[id]);
    m_player->play();
    std::cerr << "play endl" << std::endl;
    return true;
}

void MP3Player::stop()
{
    m_player->stop();
    m_currentId.clear();
}

void MP3Player::pause()
{
    m_player->pause();
}

void MP3Player::setVolume(int volume)
{
    m_player->setVolume(volume); // 75% 音量

}

QString MP3Player::currentId() const
{
    return m_currentId;
}

void MP3Player::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    qDebug() << "媒体状态变化:" << status;

    // 如果是预加载检查
    if (status == QMediaPlayer::LoadedMedia) {
        // 查找当前媒体对应的ID
        for (auto it = m_loadedFiles.begin(); it != m_loadedFiles.end(); ++it) {
            if (it.value() == m_player->media()) {
                emit fileLoaded(it.key(), true);

                // 减少待加载计数
                m_pendingLoads--;

                // 如果还有待加载的文件，加载下一个
                if (m_pendingLoads > 0 && m_loadedFiles.size() > 1) {
                    auto nextIt = std::next(it);
                    if (nextIt != m_loadedFiles.end()) {
                        m_player->setMedia(nextIt.value());
                    }
                } else if (m_pendingLoads == 0) {
                    emit allLoaded(m_allLoadsSuccessful);
                }

                break;
            }
        }
    } else if (status == QMediaPlayer::InvalidMedia) {
        // 查找当前媒体对应的ID
        for (auto it = m_loadedFiles.begin(); it != m_loadedFiles.end(); ++it) {
            if (it.value() == m_player->media()) {
                QString errorMsg = "无效媒体文件";
                if (m_player->error() != QMediaPlayer::NoError) {
                    errorMsg = m_player->errorString();
                }

                m_loadErrors[it.key()] = m_player->error();
                emit error(it.key(), errorMsg);
                emit fileLoaded(it.key(), false);

                m_allLoadsSuccessful = false;
                m_pendingLoads--;

                if (m_pendingLoads == 0) {
                    emit allLoaded(m_allLoadsSuccessful);
                }

                break;
            }
        }
    }
}

void MP3Player::onErrorOccurred(QMediaPlayer::Error error)
{
    qDebug() << "播放错误:" << error << m_player->errorString();
}


void MP3Player::slots_play(const QString& id) {
    this->play(id);
    return;
}
