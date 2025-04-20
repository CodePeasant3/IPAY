#ifndef SAVESETTINGSTRUCT_H
#define SAVESETTINGSTRUCT_H
#include <QPixmap>

namespace ipay {
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
    int length = -1;
    int width = -1;
    int height = -1;
     QImage::Format format;
};


}





#endif // SAVESETTINGSTRUCT_H
