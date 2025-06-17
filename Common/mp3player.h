#ifndef MP3PLAYER_H
#define MP3PLAYER_H

#include <QObject>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaContent>
#include <QtMultimedia/QAudioOutput>


class MP3Player : public QObject
{
    Q_OBJECT
public:
    explicit MP3Player(QObject *parent = nullptr);
    ~MP3Player();

    // 预加载单个MP3文件
    bool preload(const QString &id, const QString &filePath);
    // 预加载多个MP3文件
    bool preloadMultiple(const QMap<QString, QString> &idFilePathMap);
    // 检查文件是否已加载
    bool isLoaded(const QString &id) const;
    // 卸载已加载的文件
    void unload(const QString &id);
    // 卸载所有文件
    void unloadAll();

    // 播放指定ID的MP3
    bool play(const QString &id);
    // 停止播放
    void stop();
    // 暂停播放
    void pause();
    // 设置音量 (0.0-1.0)
    void setVolume(int volume);
    // 获取当前播放ID
    QString currentId() const;

signals:
    // 单个文件加载完成
    void fileLoaded(const QString &id, bool success);
    // 所有预加载任务完成
    void allLoaded(bool allSuccess);
    // 播放状态改变
    void stateChanged(QMediaPlayer::State state);
    // 错误发生
    void error(const QString &id, const QString &errorMsg);

private slots:
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);
    void onErrorOccurred(QMediaPlayer::Error error);

public slots:
    void slots_play(const QString& id);

private:
    QMediaPlayer *m_player;
    QMap<QString, QMediaContent> m_loadedFiles;
    QMap<QString, QMediaPlayer::Error> m_loadErrors;
    QString m_currentId;
    int m_pendingLoads;
    bool m_allLoadsSuccessful;
};

#endif // MP3PLAYER_H
