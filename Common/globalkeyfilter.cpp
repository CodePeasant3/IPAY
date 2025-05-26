// globalenterhook.cpp
#include "globalkeyfilter.h"

#include "logging.h"
#include <iostream>

GlobalEnterHook* GlobalEnterHook::m_instance = nullptr;

GlobalEnterHook::GlobalEnterHook(QObject *parent) : QObject(parent)
{
    m_hook = NULL;
    m_instance = this;
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
                m_instance->numbers.push_back(0);
            break;
        case VK_NUMPAD1:
        case VK_1:
            if(wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
                m_instance->numbers.push_back(1);
            break;
        case VK_NUMPAD2:
        case VK_2:
            if(wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
                m_instance->numbers.push_back(2);
            break;
        case VK_NUMPAD3:
        case VK_3:
            if(wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
                m_instance->numbers.push_back(3);
            break;
        case VK_NUMPAD4:
        case VK_4:
            if(wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
                m_instance->numbers.push_back(4);
            break;
        case VK_NUMPAD5:
        case VK_5:
            if(wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
                m_instance->numbers.push_back(5);
            break;
        case VK_NUMPAD6:
        case VK_6:
            if(wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
                m_instance->numbers.push_back(6);
            break;
        case VK_NUMPAD7:
        case VK_7:
            if(wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
                m_instance->numbers.push_back(7);
            break;
        case VK_NUMPAD8:
        case VK_8:
            if(wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
                m_instance->numbers.push_back(8);
            break;
        case VK_NUMPAD9:
        case VK_9:
            if(wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
            m_instance->numbers.push_back(9);
            break;
        case VK_RETURN:
            emit m_instance->enterPressed();
            std::cerr << "number: ";
            for(const auto& ele : m_instance->numbers) {
                std::cerr << ele;
            }
            std::cerr << std::endl;
            std::cerr << "---------------" << std::endl;
            m_instance->numbers.clear();
            // TODO: 分析条形码 是否需要发起支付
            break;
        }
    }

    // 传递给下一个钩子
    return CallNextHookEx(m_instance->m_hook, nCode, wParam, lParam);
}
