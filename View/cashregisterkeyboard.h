#ifndef CASHREGISTERKEYBOARD_H
#define CASHREGISTERKEYBOARD_H

#include <QWidget>

namespace Ui {
class CashRegisterKeyboard;
}

class CashRegisterKeyboard : public QWidget
{
    Q_OBJECT

public:
    explicit CashRegisterKeyboard(QWidget *parent = nullptr);
    ~CashRegisterKeyboard();
    void Init();
public slots:
    void keyboardShow();

private:
    Ui::CashRegisterKeyboard *ui;
    bool isShow_ = false;
};

#endif // CASHREGISTERKEYBOARD_H
