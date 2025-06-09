// globalenterhook.cpp
#include "globalkeyfilter.h"

#include "logging.h"
#include <iostream>
#include "globalstatuscommon.h"
#include <Common/httpsrequest.h>
#include <Common/dbops.h>

GlobalEnterHook* GlobalEnterHook::m_instance = nullptr;

GlobalEnterHook::GlobalEnterHook(HttpsRequest* request_ptr, QObject *parent) : QObject(parent)
{
    m_hook = NULL;
    m_instance = this;
    numbers.reserve(64);
    this->m_request = request_ptr;
}

GlobalEnterHook::~GlobalEnterHook()
{
    stopHook();
}

bool GlobalEnterHook::startHook()
{
    if (m_hook != NULL)
        return true;

    // 安装低级键盘钩子
    m_hook = SetWindowsHookEx(
        WH_KEYBOARD_LL,
        keyboardProc,
        GetModuleHandle(NULL),
        0
        );

    return (m_hook != NULL);
}

void GlobalEnterHook::stopHook()
{
    if (m_hook != NULL)
    {
        UnhookWindowsHookEx(m_hook);
        m_hook = NULL;
    }
}

LRESULT CALLBACK GlobalEnterHook::keyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode >= 0 && m_instance)
    {
        KBDLLHOOKSTRUCT* kbStruct = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);

        switch(kbStruct->vkCode) {
        case VK_NUMPAD0:
        case VK_0:
            if(wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
                m_instance->numbers.append("0");
            break;
        case VK_NUMPAD1:
        case VK_1:
            if(wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
                m_instance->numbers.append("1");
            break;
        case VK_NUMPAD2:
        case VK_2:
            if(wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
                m_instance->numbers.append("2");
            break;
        case VK_NUMPAD3:
        case VK_3:
            if(wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
                m_instance->numbers.append("3");
            break;
        case VK_NUMPAD4:
        case VK_4:
            if(wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
                m_instance->numbers.append("4");
            break;
        case VK_NUMPAD5:
        case VK_5:
            if(wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
                m_instance->numbers.append("5");
            break;
        case VK_NUMPAD6:
        case VK_6:
            if(wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
                m_instance->numbers.append("6");
            break;
        case VK_NUMPAD7:
        case VK_7:
            if(wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
                m_instance->numbers.append("7");
            break;
        case VK_NUMPAD8:
        case VK_8:
            if(wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
                m_instance->numbers.append("8");
            break;
        case VK_NUMPAD9:
        case VK_9:
            if(wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
            m_instance->numbers.append("9");
            break;
        case VK_RETURN:
            if(wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN){
                emit m_instance->enterPressed();
                if(m_instance->isPaymentCode()) {
                    std::string result = ipay::GlobalStatusCommon::instance()->PictureProcess();
                    m_instance->m_request->pay(m_instance->numbers, result);
                }
                else if(m_instance->isRefundCode()) {
                    // TODO: 我可以在这里获取 退款窗口是否存在吗?
                    m_instance->m_request->refund(m_instance->numbers, m_instance->numbers);
                }
                else {
                    qCritical(IPAY) << "无法解析该条形码";
                }
                m_instance->numbers.clear();
            }

            break;
        case VK_P:
            if(wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
                m_instance->numbers.append("P");
            break;
        }
    }

    // 传递给下一个钩子
    return CallNextHookEx(m_instance->m_hook, nCode, wParam, lParam);
}

std::string GlobalEnterHook::stripZero(const std::string& str) {
    size_t firstNonZero = str.find_first_not_of('0');
    if (firstNonZero == std::string::npos) {
        return "0";
    }
    return str.substr(firstNonZero);
}


bool GlobalEnterHook::isPaymentCode() {
    // 支付宝: 字符串以25到30之间的数字开头, 有16到24位数
    // 微信: 18位纯数字，以10、11、12、13、14、15开头
    // 云闪付: 有 16 个，前两个数字固定为 56
    if(numbers.size() >= 16) {
        std::string sign_code = numbers.substr(0, 2);
        qInfo(IPAY) << "sign code: " << sign_code.c_str();
        ipay::QRDetailStruct qrDetail;
        qrDetail.qr_detail = numbers;
        if(sign_code == "25" || sign_code == "26" || sign_code == "27" || sign_code == "28" ||
            sign_code == "29" || sign_code == "30") {
            qInfo(IPAY) << "支付宝付款码";
            qrDetail.qr_type = ipay::QRPaymentType::ALIPLAY;
            emit paymentQR(qrDetail);
            return true;
        }
        else if(sign_code == "10" || sign_code == "11" || sign_code == "12" || sign_code == "13"
                   || sign_code == "14" || sign_code == "15") {
            qInfo(IPAY) << "微信付款码";
            qrDetail.qr_type = ipay::QRPaymentType::WECHAT;
            emit paymentQR(qrDetail);
            return true;
        }
        else if( sign_code == "56" ) {
            qInfo(IPAY) << "云闪付付款码";
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
    return false;
}


bool GlobalEnterHook::isRefundCode() {
    qInfo(IPAY) << "code: " << numbers.c_str();
    if(numbers.size() >= 15) {
        std::string sign_code = numbers.substr(0, 1);
        qInfo(IPAY) << "sign code: " << sign_code.c_str();
        if(sign_code == "P") {
            return true;
        }
    }

    return false;
}
