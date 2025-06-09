#include "globalstatuscommon.h"
#include "opencv2/core/hal/interface.h"
#include <mutex>
#include "logging.h"

namespace ipay{

GlobalStatusCommon::GlobalStatusCommon(){}
GlobalStatusCommon::~GlobalStatusCommon(){}

void GlobalStatusCommon::ConfigInit()
{
    settings = std::make_shared<QSettings>("config.ini", QSettings::IniFormat);
    QString config_josn_path =  generic_util_.GetCurrentWorkDir() + "/config/test.json";
    QString config_picture_path =  generic_util_.GetCurrentWorkDir() + "/config/screen_picture.jpg";
    QString config_keyboard_josn_path =  generic_util_.GetCurrentWorkDir() + "/config/keyboard.json";
    QFileInfo file_info(config_josn_path);
    QPixmap  file_picture(config_picture_path);
    QFileInfo keyboard_file_info(config_josn_path);
    ipay::AllSettingConfig all_config;
    if(!file_info.exists()){
        generic_util_.CreateFileByCurrentDir(config_josn_path);
        json_common_.WirteLocalConfig(all_config,config_josn_path);
    }

    json_common_.ReadLocalConfig(all_config,config_josn_path);
    json_common_.ReadKeyboarfRrcordConfig(finsh_keyboard_playback_map_,config_keyboard_josn_path);
    keyboard_playback_map_ = finsh_keyboard_playback_map_;
    all_setting_config_ = std::make_shared<ipay::AllSettingConfig>();
    all_setting_config_->cash_register_setting = all_config.cash_register_setting;
    all_setting_config_ ->remind_setting = all_config.remind_setting;
    if(!file_picture.isNull()){
        all_setting_config_->cash_register_setting.screen_pixmap = file_picture;
    }

    ::tensorflow::TensorProto tensor_input, tensor_output;
    tensor_input.set_dtype(tensorflow::DataType::DT_FLOAT);
    tensor_input.mutable_tensor_shape()->add_dim()->set_size(1);
    tensor_input.mutable_tensor_shape()->add_dim()->set_size(640);
    tensor_input.mutable_tensor_shape()->add_dim()->set_size(640);
    tensor_input.mutable_tensor_shape()->add_dim()->set_size(3);
    tensor_output.set_dtype(tensorflow::DataType::DT_FLOAT);
    tensor_output.mutable_tensor_shape()->add_dim()->set_size(1);
    tensor_output.mutable_tensor_shape()->add_dim()->set_size(15);
    tensor_output.mutable_tensor_shape()->add_dim()->set_size(8400);

    int ret = 0;
    auto infer_server = settings->value(QString("Infer/Server")).toString();
    qWarning() << "read from ini file, server: " << infer_server;


  ret = client.Init(infer_server.toStdString(),
                    std::move(tensor_input), std::move(tensor_output), "num_1-on-featurize");
  if(ret) {
      qCritical(IPAY) << "Link remote server Failed" << infer_server;
      return;
  }
  else{
      qCritical(IPAY) << "Link remote server Success" << infer_server;
      ::tensorflow::serving::GetModelMetadataResponse response_meta;
      client.GetModelMetadata(&response_meta);
      qInfo(IPAY) << "model.name: " << response_meta.model_spec().name().c_str();
      qInfo(IPAY) << "model.version: " << response_meta.model_spec().version().value();
      qInfo(IPAY) << "model.signature_name: " << response_meta.model_spec().signature_name().c_str();
  }



    auto mchNo = settings->value("Business/mchNo").toString();
    auto appId = settings->value("Business/appId").toString();

    qWarning() << "read from ini file, mchNo: " << mchNo;
    qWarning() << "read from ini file, appId: " << appId;



}

void GlobalStatusCommon::ModifyCashRegisterSetting(const CashRegisterSettingStruct & cash_register_setting_struct)
{
    all_setting_config_->cash_register_setting = cash_register_setting_struct;
    FinshConfig();
}

void GlobalStatusCommon::ModifyCashRegisterSettingNotWrite(const CashRegisterSettingStruct &cash_register_setting_struct)
{
    all_setting_config_->cash_register_setting = cash_register_setting_struct;
}

void GlobalStatusCommon::ModifyRemindSetting(const RemindSettingStruct &remind_setting_struct)
{
    all_setting_config_ ->remind_setting = remind_setting_struct;
    FinshConfig();
}

void GlobalStatusCommon::ModifyRemindSettingNotWrite(const RemindSettingStruct &remind_setting_struct)
{
    all_setting_config_ ->remind_setting = remind_setting_struct;
}

void GlobalStatusCommon::FinshConfig()
{
    std::unordered_map<ipay::ScenePlaybackType,std::vector<KeyboardMouseRecordStruct>> tempMap =  keyboard_playback_map_;
    finsh_keyboard_playback_map_.clear();
    finsh_keyboard_playback_map_ = tempMap;
    QString config_josn_path =  generic_util_.GetCurrentWorkDir() + "/config/test.json";
    json_common_.WirteLocalConfig(*all_setting_config_,config_josn_path);
    QString config_picture_path =  generic_util_.GetCurrentWorkDir() + "/config/screen_picture.jpg";
    all_setting_config_->cash_register_setting.screen_pixmap.save(config_picture_path,"jpg");
    QString config_keyboard_josn_path =  generic_util_.GetCurrentWorkDir() + "/config/keyboard.json";
    json_common_.WirteKeyboarfRrcordConfig(tempMap,config_keyboard_josn_path);



}
std::string GlobalStatusCommon::PictureProcess() {
    std::lock_guard<std::mutex> lock_(mtx_);
    std::string tmp = ret_amount;
    return tmp;
}


void GlobalStatusCommon::WhileDetect()
{
    while(this->ok) {
       qDebug(IPAY) << "One second has passed.";
        cv::Mat screenCaptureData;
        GetPictureData(screenCaptureData);
        if(!screenCaptureData.empty()) {
            // cv::imshow("capture image", screenCaptureData);
            // cv::waitKey(1);
            std::lock_guard<std::mutex> lock_(mtx_);
           ret_amount = client.Predict(std::move(screenCaptureData), 0.2f);
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

}


std::shared_ptr<AllSettingConfig> GlobalStatusCommon::GetAllSettingConfig()
{
    return all_setting_config_;
}

void GlobalStatusCommon::GetPictureData(cv::Mat& screenCaptureData)
{
    generic_util_.CaptureScreen(all_setting_config_->cash_register_setting,screenCaptureData);
}

void GlobalStatusCommon::StartRecordKeyboard(ipay::ScenePlaybackType currentType)
{
    current_type_ = currentType;
}

void  GlobalStatusCommon::StopRecordKeyboard(std::vector<KeyboardMouseRecordStruct> & keyboardVector)
{
    keyboard_playback_map_[current_type_].clear();
    keyboard_playback_map_[current_type_] = std::move(keyboardVector);
}

std::shared_ptr<AllSettingConfig> GlobalStatusCommon::GetSettingConfig()
{
    return all_setting_config_;
}


std::vector<KeyboardMouseRecordStruct>& GlobalStatusCommon::GetKeyboardMouseList(ipay::ScenePlaybackType type)
{
    return keyboard_playback_map_[type];
}

std::vector<KeyboardMouseRecordStruct> &GlobalStatusCommon::GetFinshKeyboardMouseList(ScenePlaybackType type)
{
    return finsh_keyboard_playback_map_[type];
}

QRect GlobalStatusCommon::GetScreenScope()
{
    ipay::PrimaryScreen primaryScreen;
    return primaryScreen.GetGeometryScreen();
}

void GlobalStatusCommon::unsetOK() {
    qWarning() << "set atomic ok is false;";
    this->ok = false;
}

}
