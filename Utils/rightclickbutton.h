#ifndef RIGHTCLICKBUTTON_H
#define RIGHTCLICKBUTTON_H

#include <QPushButton>
#include <QWidget>
#include <QMouseEvent>
#include <QMenu>
#include <QDebug>

// 自定义按钮类，重写 mousePressEvent 方法
class RightClickButton : public QPushButton
{
    Q_OBJECT
public:
    explicit RightClickButton(QWidget *parent = nullptr) : QPushButton(parent) {}

protected:
    void mousePressEvent(QMouseEvent *event) override
    {
        if (event->button() == Qt::RightButton) {
                    if (menu()) {
                        // 获取按钮的全局位置
                        QPoint globalPos = mapToGlobal(QPoint(0, height()));
                        // 在按钮下方弹出菜单，和左键默认弹出位置一致
                        menu()->exec(globalPos);
                    }
                } else if (event->button() == Qt::LeftButton) {
                    return;
                } else {
                    // 其他鼠标按钮点击，执行默认行为
                    QPushButton::mousePressEvent(event);
                }
    }
};



#endif // RIGHTCLICKBUTTON_H
