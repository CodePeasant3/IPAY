// globalenterhook.h
#ifndef GLOBALENTERHOOK_H
#define GLOBALENTERHOOK_H

#include <QObject>
#include <Windows.h>
#include <vector>
#include "savesettingstruct.h"

#ifndef VK_A
#define VK_A 0x41
#endif

#ifndef VK_B
#define VK_B 0x42
#endif

#ifndef VK_C
#define VK_C 0x43
#endif

#ifndef VK_D
#define VK_D 0x44
#endif

#ifndef VK_E
#define VK_E 0x45
#endif

#ifndef VK_F
#define VK_F 0x46
#endif

#ifndef VK_G
#define VK_G 0x47
#endif

#ifndef VK_H
#define VK_H 0x48
#endif

#ifndef VK_I
#define VK_I 0x49
#endif

#ifndef VK_J
#define VK_J 0x4A
#endif

#ifndef VK_K
#define VK_K 0x4B
#endif

#ifndef VK_L
#define VK_L 0x4C
#endif

#ifndef VK_M
#define VK_M 0x4D
#endif

#ifndef VK_N
#define VK_N 0x4E
#endif

#ifndef VK_O
#define VK_O 0x4F
#endif

#ifndef VK_P
#define VK_P 0x50
#endif

#ifndef VK_Q
#define VK_Q 0x51
#endif

#ifndef VK_R
#define VK_R 0x52
#endif

#ifndef VK_S
#define VK_S 0x53
#endif

#ifndef VK_T
#define VK_T 0x54
#endif

#ifndef VK_U
#define VK_U 0x55
#endif

#ifndef VK_V
#define VK_V 0x56
#endif

#ifndef VK_W
#define VK_W 0x57
#endif

#ifndef VK_X
#define VK_X 0x58
#endif

#ifndef VK_Y
#define VK_Y 0x59
#endif

#ifndef VK_Z
#define VK_Z 0x5A
#endif

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
    bool isPaymentCode(); // 判断是否是收款码
    bool isRefundCode(); // 判断是否是退款码

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
    std::string stripZero(const std::string& str);
private:
    HttpsRequest* m_request;
};

#endif // GLOBALENTERHOOK_H
