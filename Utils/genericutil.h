#ifndef GENERICUTIL_H
#define GENERICUTIL_H
#include <QString>
#include <QDir>
#include <QDebug>
#include <QGuiApplication>
#include <QScreen>
#include "../Common/savesettingstruct.h"
#include <QMessageBox>

namespace ipay{

#define IPAY_DECLARE_SINGLETON(ClassName)           \
    \
    public : static ClassName*                 \
             instance() {                      \
        static ClassName instance;             \
        return &instance;                      \
    }                                          \
                                               \
private:                                       \
    ClassName();                               \
    ~ClassName();                              \
    ClassName(const ClassName&) = delete;      \
    ClassName& operator=(const ClassName&) = delete;

class GenericUtil
{
public:
    GenericUtil();
    bool FileExists(QString path);
    QString GetCurrentWorkDir();
    bool CreateFileByCurrentDir(QString path);
    void CaptureScreen(const ipay::CashRegisterSettingStruct &cash_register_setting_struct,ScreenCaptureData& screenCaptureData);


private:
//    ipay::ScreenCaptureData screenCaptureData_;

};




}


#endif // GENERICUTIL_H
