#ifndef JSONOPERATIONCOMMON_H
#define JSONOPERATIONCOMMON_H
#include "savesettingstruct.h"
#include "genericutil.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QString>
#include <QJsonArray>

namespace ipay {

class JsonOperationCommon
{
public:
    bool WirteLocalConfig(const ipay::AllSettingConfig &all_setting_condfig,const QString &full_path);
    bool ReadLocalConfig(ipay::AllSettingConfig &all_setting_condfig, const QString &full_path);

    bool WirteKeyboarfRrcordConfig(const std::unordered_map<ipay::ScenePlaybackType,std::vector<KeyboardMouseRecordStruct>>& keyboard_playback_map
                                   ,const QString &full_path);
    bool ReadKeyboarfRrcordConfig(std::unordered_map<ipay::ScenePlaybackType,std::vector<KeyboardMouseRecordStruct>>& keyboard_playback_map
                                   ,const QString &full_path);
    QJsonObject ReadJsonFromFile(const QString& full_path);

private:
};

}


#endif // JSONOPERATIONCOMMON_H
