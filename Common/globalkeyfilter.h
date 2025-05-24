// globalenterhook.h
#ifndef GLOBALENTERHOOK_H
#define GLOBALENTERHOOK_H

#include <QObject>
#include <Windows.h>

class GlobalEnterHook : public QObject
{
    Q_OBJECT
public:
    explicit GlobalEnterHook(QObject *parent = nullptr);
    ~GlobalEnterHook();

    // 启动和停止监听
    bool startHook();
    void stopHook();

signals:
    // 回车键按下信号
    void enterPressed();
    // 回车键释放信号
    void enterReleased();

private:
    // 键盘钩子回调函数
    static LRESULT CALLBACK keyboardProc(int nCode, WPARAM wParam, LPARAM lParam);

    // 钩子句柄
    HHOOK m_hook;

    // 静态实例指针，用于回调函数访问
    static GlobalEnterHook* m_instance;
};

#endif // GLOBALENTERHOOK_H
