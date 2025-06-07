// globalenterhook.h
#ifndef GLOBALENTERHOOK_H
#define GLOBALENTERHOOK_H

#include <QObject>
#include <Windows.h>
#include <vector>
#include "savesettingstruct.h"

#ifndef VK_0
#define VK_0 0x30  // 数字0键的Windows虚拟键码
#endif

#ifndef VK_1
#define VK_1 0x31  // 数字1键的Windows虚拟键码
#endif

#ifndef VK_2
#define VK_2 0x32  // 数字2键的Windows虚拟键码
#endif

#ifndef VK_3
#define VK_3 0x33  // 数字2键的Windows虚拟键码
#endif

#ifndef VK_4
#define VK_4 0x34  // 数字2键的Windows虚拟键码
#endif

#ifndef VK_5
#define VK_5 0x35  // 数字2键的Windows虚拟键码
#endif

#ifndef VK_6
#define VK_6 0x36  // 数字2键的Windows虚拟键码
#endif

#ifndef VK_7
#define VK_7 0x37  // 数字2键的Windows虚拟键码
#endif

#ifndef VK_8
#define VK_8 0x38  // 数字2键的Windows虚拟键码
#endif

#ifndef VK_9
#define VK_9 0x39  // 数字2键的Windows虚拟键码
#endif

class HttpsRequest;
class DBOps;

class GlobalEnterHook : public QObject
{
    Q_OBJECT
public:
    GlobalEnterHook(HttpsRequest*, QObject *parent = nullptr);
    ~GlobalEnterHook();

    // 启动和停止监听
    bool startHook();
    void stopHook();
    bool isPaymentCode();

signals:
    // 回车键按下信号
    void enterPressed();
    // 回车键释放信号
    void enterReleased();
    void paymentQR(const ipay::QRDetailStruct &qr_struct);

private:
    // 键盘钩子回调函数
    static LRESULT CALLBACK keyboardProc(int nCode, WPARAM wParam, LPARAM lParam);

    // 钩子句柄
    HHOOK m_hook;

    // 静态实例指针，用于回调函数访问
    static GlobalEnterHook* m_instance;
    std::string numbers;
private:
    HttpsRequest* m_request;
};

#endif // GLOBALENTERHOOK_H
