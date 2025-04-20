#ifndef JSONOPERATIONCOMMON_H
#define JSONOPERATIONCOMMON_H
#include "savesettingstruct.h"
#include "genericutil.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QString>

namespace ipay {

class JsonOperationCommon
{
public:
    bool WirteLocalConfig(const ipay::AllSettingConfig &all_setting_condfig,const QString &full_path);
    bool ReadLocalConfig(ipay::AllSettingConfig &all_setting_condfig, const QString &full_path);
    QJsonObject ReadJsonFromFile(const QString& full_path);

private:
};

}


#endif // JSONOPERATIONCOMMON_H
