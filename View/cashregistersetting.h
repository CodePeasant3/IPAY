#ifndef CASHREGISTERSETTING_H
#define CASHREGISTERSETTING_H
#include <QWidget>
#include <QIntValidator>
#include "../Common/globalstatuscommon.h"
#include "../Common/screen.h"

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
    void UIStatus();
    void CreateWidgetItem();

signals:
    void start_keyboard_record();
    void hideSettingPage();

private slots:
    void on_pushButton_recognition_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_cancel_clicked();
    void RegisterArea();

    void on_pushButton_record_clicked();

    void on_pushButton_auto_clean_clicked();

    void on_radioButton_money_back_clicked();
    void close_screen();
    void save_picture();
private:
    Ui::CashRegisterSetting *ui;
    Screen  *scr_ = nullptr;
    ipay::CashRegisterSettingStruct cash_register_setting_struct_;

};

#endif // CASHREGISTERSETTING_H
