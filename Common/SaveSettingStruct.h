#ifndef SAVESETTINGSTRUCT_H
#define SAVESETTINGSTRUCT_H
#include <QPixmap>
#include <QListWidgetItem>

namespace ipay {

// 录制类型
enum KeyboardMouseType{
  LIFTMOUSE = 0,
  RIGHTMOUSE,
  KETBOARD
};

//录制场景功能
enum ScenePlaybackType{
  CALLBACKCLEANTABLE = 0, // clean_table
  CALLBACKPAYDONE // pay_done
};

enum QRPaymentType{
  ALIPLAY = 0, // 支付宝
  WECHAT // 微信
};


enum KeyboardOperationType{
    COLLECTION = 0,
    MODIAY
};


struct KeyboardMouseRecordStruct{
    KeyboardMouseType type;
    std::string value;
//    unsigned long key_num;
    long key_num;
    int mouse_x;
    int mouse_y;
    int record_index;
};


struct BaseSeting
{

};


struct CashRegisterSettingStruct{
    int automatic_money_entry = 0; // 0 自动， 1 手动
//    bool read_statment = true;
    int recognition_type = 0; // 0 实时， 1 扫码后识别
    int screen_x = -1;
    int screen_y = -1;
    int screen_w = 0;
    int screen_h = 0;
    QPixmap screen_pixmap;
    int screen_pixmap_w = 0;
    int screen_pixmap_h = 0;
    bool is_hide = false;
    //=============清台设置===============
    int automatic_amount_entry = 0; // 0 自动， 1 手动
    int interaval_entry_ms = 0;
    int enable_money_playback = 0; // 0 不回填 ,1 回填



};


struct RemindSettingStruct {
    bool voice_remoid = true; // true 开启 ， false 关闭
};

struct AllSettingConfig{
    CashRegisterSettingStruct cash_register_setting;
    RemindSettingStruct remind_setting;
};

struct ScreenCaptureData {
    uchar* data = nullptr;
    int length = 0;
    int width = 0;
    int height = 0;
    QImage::Format format;
    ~ScreenCaptureData() {
        delete[] data;
    }
};


using ScreenCaptureDataPtr =  std::shared_ptr<ipay::ScreenCaptureData>;
using GetPictureDataCallBack = std::function<void(ScreenCaptureDataPtr)>;

//识别结果
struct IdentifyResults{



};

struct QRDetailStruct
{
  std::string qr_detail;
  QRPaymentType qr_type;
};



}


























#endif // SAVESETTINGSTRUCT_H
