#include "jsonoperationcommon.h"
#include <Common/logging.h>
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
    obj["interaval_refund_done_ms"] = setting.interaval_refund_done_ms;
    obj["refund_amount_entry"] = setting.refund_amount_entry;
    obj["enable_money_refund"] = setting.enable_money_refund;
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
    if (json.contains("interaval_refund_done_ms") && json["interaval_refund_done_ms"].isDouble()) {
        setting.interaval_refund_done_ms = json["interaval_refund_done_ms"].toInt();
    }
    if (json.contains("refund_amount_entry") && json["refund_amount_entry"].isDouble()) {
        setting.refund_amount_entry = json["refund_amount_entry"].toInt();
    }
    if (json.contains("enable_money_refund") && json["enable_money_refund"].isDouble()) {
        setting.enable_money_refund = json["enable_money_refund"].toInt();
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
        qCritical(IPAY) << "无法打开文件进行写入: " << full_path;
        return false;
    }

    QJsonDocument json_doc(json_object);
    QByteArray json_data = json_doc.toJson(QJsonDocument::Indented);
    file.write(json_data);
    file.close();
    qInfo(IPAY) << "JSON数据已成功写入文件: " << full_path;

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

bool JsonOperationCommon::WirteKeyboarfRrcordConfig(const std::unordered_map<ScenePlaybackType, std::vector<KeyboardMouseRecordStruct> > &keyboard_playback_map, const QString &full_path)
{
    QJsonObject rootObject;

    for (const auto &pair : keyboard_playback_map) {
        ScenePlaybackType sceneType = pair.first;
        const std::vector<KeyboardMouseRecordStruct> &records = pair.second;
        QJsonArray sceneArray;
        for (const auto &record : records) {
            QJsonObject recordObject;
            switch (record.type) {
                case LIFTMOUSE:
                    recordObject["type"] = "LIFTMOUSE";
                    break;
                case RIGHTMOUSE:
                    recordObject["type"] = "RIGHTMOUSE";
                    break;
                case KETBOARD:
                    recordObject["type"] = "KETBOARD";
                    break;
            }
            recordObject["value"] = QString::fromStdString(record.value);
            recordObject["key_num"] = static_cast<qint64>(record.key_num);
            recordObject["mouse_x"] = record.mouse_x;
            recordObject["mouse_y"] = record.mouse_y;
            recordObject["record_index"] = record.record_index;

            sceneArray.append(recordObject);
        }

        rootObject[QString::number(static_cast<int>(sceneType))] = sceneArray;
    }

    QJsonDocument jsonDoc(rootObject);

    QFile file(full_path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "无法打开文件:" << full_path;
        return false;
    }

    file.write(jsonDoc.toJson(QJsonDocument::Indented));
    file.close();

    return true;


}

bool JsonOperationCommon::ReadKeyboarfRrcordConfig(std::unordered_map<ScenePlaybackType, std::vector<KeyboardMouseRecordStruct> > &keyboard_playback_map, const QString &full_path)
{

    keyboard_playback_map.clear();

    QFile file(full_path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "can't open json file :" << full_path;
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "json file analysis :" << parseError.errorString();
        return false;
    }

    if (!jsonDoc.isObject()) {
        qDebug() << "json file document is error!";
        return false;
    }
    QJsonObject rootObject = jsonDoc.object();

    for (const QString &sceneKey : rootObject.keys()) {

        bool ok;
        int sceneTypeInt = sceneKey.toInt(&ok);
        if (!ok) {
            qDebug() << "无法将场景键转换为整数:" << sceneKey;
            continue;
        }

        if (sceneTypeInt < 0 || sceneTypeInt > static_cast<int>(ipay::ScenePlaybackType::CALLTOTAL)) {
            qDebug() << "无效的场景类型:" << sceneTypeInt;
            continue;
        }

        ScenePlaybackType sceneType = static_cast<ScenePlaybackType>(sceneTypeInt);

        if (!rootObject[sceneKey].isArray()) {
            qDebug() << "场景数据不是数组类型:" << sceneKey;
            continue;
        }

        QJsonArray sceneArray = rootObject[sceneKey].toArray();

        std::vector<KeyboardMouseRecordStruct> records;

        int index_i = 0;
        for (const QJsonValue &recordValue : sceneArray) {
            if (!recordValue.isObject()) {
                qDebug() << "记录不是对象类型";
                continue;
            }

            QJsonObject recordObj = recordValue.toObject();
            KeyboardMouseRecordStruct record;

            QString typeStr = recordObj["type"].toString();
            if (typeStr == "LIFTMOUSE") {
                record.type = LIFTMOUSE;
            } else if (typeStr == "RIGHTMOUSE") {
                record.type = RIGHTMOUSE;
            } else if (typeStr == "KETBOARD") {
                record.type = KETBOARD;
            } else {
                qDebug() << "未知的记录类型:" << typeStr;
                continue;
            }

            record.value = recordObj["value"].toString().toStdString();
            record.key_num = recordObj["key_num"].toVariant().toLongLong();
            record.mouse_x = recordObj["mouse_x"].toInt();
            record.mouse_y = recordObj["mouse_y"].toInt();
            record.record_index = index_i;

            records.push_back(record);
            ++index_i;
        }
        keyboard_playback_map[sceneType] = std::move(records);

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
