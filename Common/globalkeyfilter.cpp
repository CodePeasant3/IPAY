// globalenterhook.cpp
#include "globalkeyfilter.h"

#include "logging.h"

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

        // 只处理回车键（VK_RETURN）
        if (kbStruct->vkCode == VK_RETURN)
        {
            qDebug(IPAY) << "Listen, 监听到USB扫码枪的键盘事件";
            // 发送按键事件
            if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
                emit m_instance->enterPressed();
            else if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
                emit m_instance->enterReleased();
        }
    }

    // 传递给下一个钩子
    return CallNextHookEx(m_instance->m_hook, nCode, wParam, lParam);
}
