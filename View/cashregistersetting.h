#ifndef CASHREGISTERSETTING_H
#define CASHREGISTERSETTING_H

#include <QWidget>

namespace Ui {
class CashRegisterSetting;
}

class CashRegisterSetting : public QWidget
{
    Q_OBJECT

public:
    explicit CashRegisterSetting(QWidget *parent = nullptr);
    ~CashRegisterSetting();

private:
    Ui::CashRegisterSetting *ui;
};

#endif // CASHREGISTERSETTING_H
