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
private:
    QTimer *process_timer_{nullptr};
    ipay::JsonOperationCommon json_common_;
    ipay::GenericUtil generic_util_;
    std::shared_ptr<ipay::AllSettingConfig> all_setting_config_{nullptr};

public:
    IPAY_DECLARE_SINGLETON(GlobalStatusCommon);
};
}


#endif // GLOBALSTATUSCOMMON_H
