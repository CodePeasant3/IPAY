#ifndef GLOBALSTATUSCOMMON_H
#define GLOBALSTATUSCOMMON_H
#include "genericutil.h"
#include "jsonoperationcommon.h"
#include "savesettingstruct.h"
#include <QTimer>
#include "dbops.h"
#include <QSettings>

#include <PredictionClient.h>
#include <opencv2/opencv.hpp>
namespace ipay{
class GlobalStatusCommon
{
public:
    void ConfigInit();
    void ModifyCashRegisterSetting(const CashRegisterSettingStruct & cash_register_setting_struct);
    void ModifyCashRegisterSettingNotWrite(const CashRegisterSettingStruct & cash_register_setting_struct);
    void ModifyRemindSetting(const RemindSettingStruct& remind_setting_struct);
    void ModifyRemindSettingNotWrite(const RemindSettingStruct& remind_setting_struct);
    void FinshConfig();
    IdentifyResults PictureProcess();
    std::shared_ptr<ipay::AllSettingConfig> GetAllSettingConfig();
    void GetPictureData(cv::Mat& screenCaptureData);
    void StartRecordKeyboard(ipay::ScenePlaybackType currentType);
    void StopRecordKeyboard(std::vector<KeyboardMouseRecordStruct> & keyboardVector);
    std::shared_ptr<ipay::AllSettingConfig> GetSettingConfig();

public:
    DBOps db_ops;
    std::shared_ptr<QSettings> settings;

private:
    ipay::JsonOperationCommon json_common_;
    ipay::GenericUtil generic_util_;
    std::shared_ptr<ipay::AllSettingConfig> all_setting_config_{nullptr};
    std::unordered_map<ipay::ScenePlaybackType,std::vector<KeyboardMouseRecordStruct>> keyboard_playback_map_;
    ipay::ScenePlaybackType current_type_;
//    PredictionClient client;

public:
    IPAY_DECLARE_SINGLETON(GlobalStatusCommon);
};
}


#endif // GLOBALSTATUSCOMMON_H
