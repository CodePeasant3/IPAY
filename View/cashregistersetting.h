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
    void Init();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::CashRegisterSetting *ui;
};

#endif // CASHREGISTERSETTING_H
