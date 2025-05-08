#ifndef GLOBALSTATUSCOMMON_H
#define GLOBALSTATUSCOMMON_H
#include "genericutil.h"
#include "jsonoperationcommon.h"
#include "savesettingstruct.h"
#include <QTimer>

namespace ipay{
class GlobalStatusCommon
{
public:
    void ConfigInit();
    void ModifyCashRegisterSetting(const CashRegisterSettingStruct & cash_register_setting_struct);
    void ModifyRemindSetting(const RemindSettingStruct& remind_setting_struct);
    void FinshConfig();
    void PictureProcess();
    std::shared_ptr<ipay::AllSettingConfig> GetAllSettingConfig();
    ScreenCaptureData GetPictureData();
    void StartRecordKeyboard(ipay::ScenePlaybackType currentType);
    void StopRecordKeyboard(std::vector<KeyboardMouseRecordStruct> & keyboardVector);
private:
    QTimer *process_timer_{nullptr};
    ipay::JsonOperationCommon json_common_;
    ipay::GenericUtil generic_util_;
    std::shared_ptr<ipay::AllSettingConfig> all_setting_config_{nullptr};
    std::unordered_map<ipay::ScenePlaybackType,std::vector<KeyboardMouseRecordStruct>> keyboard_playback_map_;
    ipay::ScenePlaybackType current_type_;

public:
    IPAY_DECLARE_SINGLETON(GlobalStatusCommon);
};
}


#endif // GLOBALSTATUSCOMMON_H
