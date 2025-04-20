#include "jsonoperationcommon.h"
namespace ipay {

QJsonObject CashRegisterSettingToJson(const CashRegisterSettingStruct& setting) {
    QJsonObject obj;
    obj["automatic_money_entry"] = setting.automatic_money_entry;
//    obj["read_statment"] = setting.read_statment;
    obj["recognition_type"] = setting.recognition_type;
    obj["screen_x"] = setting.screen_x;
    obj["screen_y"] = setting.screen_y;
    obj["screen_w"] = setting.screen_w;
    obj["screen_h"] = setting.screen_h;
    obj["screen_pixmap_w"] = setting.screen_pixmap_w;
    obj["screen_pixmap_h"] = setting.screen_pixmap_h;
    obj["automatic_amount_entry"] = setting.automatic_amount_entry;
    obj["interaval_entry_ms"] = setting.interaval_entry_ms;
    obj["enable_money_playback"] = setting.enable_money_playback;
    return obj;
}

QJsonObject RemindSettingToJson(const RemindSettingStruct& setting) {
    QJsonObject obj;
    obj["voice_remoid"] = setting.voice_remoid;
    return obj;
}

void JsonToCashRegisterSetting(const QJsonObject& json, CashRegisterSettingStruct& setting) {
    if (json.contains("automatic_money_entry") && json["automatic_money_entry"].isDouble()) {
        setting.automatic_money_entry = json["automatic_money_entry"].toInt();
    }
//    if (json.contains("read_statment") && json["read_statment"].isBool()) {
//        setting.read_statment = json["read_statment"].toBool();
//    }
    if (json.contains("recognition_type") && json["recognition_type"].isDouble()) {
        setting.recognition_type = json["recognition_type"].toInt();
    }
    if (json.contains("screen_x") && json["screen_x"].isDouble()) {
        setting.screen_x = json["screen_x"].toInt();
    }
    if (json.contains("screen_y") && json["screen_y"].isDouble()) {
        setting.screen_y = json["screen_y"].toInt();
    }
    if (json.contains("screen_w") && json["screen_w"].isDouble()) {
        setting.screen_w = json["screen_w"].toInt();
    }
    if (json.contains("screen_h") && json["screen_h"].isDouble()) {
        setting.screen_h = json["screen_h"].toInt();
    }
    if (json.contains("automatic_amount_entry") && json["automatic_amount_entry"].isDouble()) {
        setting.automatic_amount_entry = json["automatic_amount_entry"].toInt();
    }
    if (json.contains("interaval_entry_ms") && json["interaval_entry_ms"].isDouble()) {
        setting.interaval_entry_ms = json["interaval_entry_ms"].toInt();
    }
    if (json.contains("enable_money_playback") && json["enable_money_playback"].isDouble()) {
        setting.enable_money_playback = json["enable_money_playback"].toInt();
    }
    if (json.contains("screen_pixmap_w") && json["screen_pixmap_w"].isDouble()) {
        setting.screen_pixmap_w = json["screen_pixmap_w"].toInt();
    }
    if (json.contains("screen_pixmap_h") && json["screen_pixmap_h"].isDouble()) {
        setting.screen_pixmap_h = json["screen_pixmap_h"].toInt();
    }
}

void JsonToRemindSetting(const QJsonObject& json, RemindSettingStruct& setting) {
    if (json.contains("voice_remoid") && json["voice_remoid"].isBool()) {
        setting.voice_remoid = json["voice_remoid"].toBool();
    }
}


bool JsonOperationCommon::WirteLocalConfig(const ipay::AllSettingConfig &all_setting_condfig,const QString &full_path)
{

    QJsonObject json_object;
    json_object["cash_register_setting"] = CashRegisterSettingToJson(all_setting_condfig.cash_register_setting);
    json_object["remind_setting"] = RemindSettingToJson(all_setting_condfig.remind_setting);

    QFile file(full_path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "无法打开文件进行写入: " << full_path;
        return false;
    }

    QJsonDocument json_doc(json_object);
    QByteArray json_data = json_doc.toJson(QJsonDocument::Indented);
    file.write(json_data);
    file.close();
    qDebug() << "JSON数据已成功写入文件: " << full_path;

    return true;
}

bool JsonOperationCommon::ReadLocalConfig(AllSettingConfig &all_setting_condfig,const QString &full_path)
{
    QJsonObject json_obj = ReadJsonFromFile(full_path);
    if (json_obj.contains("cash_register_setting") && json_obj["cash_register_setting"].isObject()) {
        JsonToCashRegisterSetting(json_obj["cash_register_setting"].toObject(), all_setting_condfig.cash_register_setting);
    }
    if (json_obj.contains("remind_setting") && json_obj["remind_setting"].isObject()) {
        JsonToRemindSetting(json_obj["remind_setting"].toObject(), all_setting_condfig.remind_setting);
    }
    return true;

}

QJsonObject JsonOperationCommon::ReadJsonFromFile(const QString &full_path)
{
    QFile file(full_path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QByteArray data = file.readAll();
        file.close();
        QJsonDocument json_doc = QJsonDocument::fromJson(data);
        if (!json_doc.isNull() && json_doc.isObject()) {
            return json_doc.object();
        }
    }
    return QJsonObject();
};

}
