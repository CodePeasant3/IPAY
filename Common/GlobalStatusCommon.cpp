#include "globalstatuscommon.h"
#include "opencv2/core/hal/interface.h"
#include <opencv2/opencv.hpp>
#include <mutex>

namespace ipay{

GlobalStatusCommon::GlobalStatusCommon(){}
GlobalStatusCommon::~GlobalStatusCommon(){
    if(process_timer_){
        process_timer_->stop();
        delete process_timer_;
        process_timer_ = nullptr;
    }
}
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

    int ret = client.Init("123.138.200.114:8010",
                          std::move(tensor_input), std::move(tensor_output), "num_1-on-featurize");
    if(ret) {
        qCritical() << "Link remote server 123.138.200.114:8010 Failed";
        return;
    }else{
        qWarning() << "Link remote server 123.138.200.114:8010 success";
        ::tensorflow::serving::GetModelMetadataResponse response_meta;
        client.GetModelMetadata(&response_meta);
        qInfo() << "model.name: " << response_meta.model_spec().name().c_str();
        qInfo() << "model.version: " << response_meta.model_spec().version().value();
        qInfo() << "model.signature_name: " << response_meta.model_spec().signature_name().c_str();
    }


    if(!process_timer_){
        process_timer_ = new QTimer();
        process_timer_->setInterval(1000);
        QObject::connect(process_timer_, &QTimer::timeout, [this]() {
            if(all_setting_config_->cash_register_setting.recognition_type == 1){
                return;
            }
             PictureProcess();
        });
        process_timer_->start();
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

IdentifyResults GlobalStatusCommon::PictureProcess()
{
    IdentifyResults result;
    qDebug() << "One second has passed.";
    cv::Mat screenCaptureData;
    GetPictureData(screenCaptureData);
    if(!screenCaptureData.empty()) {
        cv::imshow("capture image", screenCaptureData);
        cv::waitKey(1);
    }

    return result;
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


}
