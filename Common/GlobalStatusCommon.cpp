#include "globalstatuscommon.h"

namespace ipay{

GlobalStatusCommon::GlobalStatusCommon(){}
GlobalStatusCommon::~GlobalStatusCommon(){}
void GlobalStatusCommon::ConfigInit()
{

    QString config_josn_path =  generic_util_.GetCurrentWorkDir() + "/config/test.json";
    QString config_picture_path =  generic_util_.GetCurrentWorkDir() + "/config/screen_picture.jpg";
    QFileInfo file_info(config_josn_path);
    QPixmap  file_picture(config_picture_path);
    ipay::AllSettingConfig all_config;
    if(!file_info.exists()){
        generic_util_.CreateFileByCurrentDir(config_josn_path);
        json_common_.WirteLocalConfig(all_config,config_josn_path);
    }
    json_common_.ReadLocalConfig(all_config,config_josn_path);
    all_setting_config_ = std::make_shared<ipay::AllSettingConfig>();
    all_setting_config_->cash_register_setting = all_config.cash_register_setting;
    all_setting_config_ ->remind_setting = all_config.remind_setting;
    if(!file_picture.isNull()){
        all_setting_config_->cash_register_setting.screen_pixmap = file_picture;
    }
}

void GlobalStatusCommon::ModifyCashRegisterSetting(const CashRegisterSettingStruct & cash_register_setting_struct)
{
    all_setting_config_->cash_register_setting = cash_register_setting_struct;
    FinshConfig();
}

void GlobalStatusCommon::ModifyRemindSetting(const RemindSettingStruct &remind_setting_struct)
{
    all_setting_config_ ->remind_setting = remind_setting_struct;
    FinshConfig();
}

void GlobalStatusCommon::FinshConfig()
{
    QString config_josn_path =  generic_util_.GetCurrentWorkDir() + "/config/test.json";
    json_common_.WirteLocalConfig(*all_setting_config_,config_josn_path);
    QString config_picture_path =  generic_util_.GetCurrentWorkDir() + "/config/screen_picture.jpg";
    all_setting_config_->cash_register_setting.screen_pixmap.save(config_picture_path,"jpg");
}

std::shared_ptr<AllSettingConfig> GlobalStatusCommon::GetAllSettingConfig()
{
    return all_setting_config_;
}

ScreenCaptureData GlobalStatusCommon::GetPictureData()
{
    return generic_util_.CaptureScreen(all_setting_config_->cash_register_setting);
}


}
