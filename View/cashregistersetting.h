#ifndef CASHREGISTERSETTING_H
#define CASHREGISTERSETTING_H
#include <QWidget>
#include <QIntValidator>
#include "../Common/globalstatuscommon.h"
#include "../Common/screen.h"
#include "../View/keyboardmousetemplate.h"
#include <QDebug>
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
    QListWidgetItem* GetQListWidget(ipay::ScenePlaybackType type, int index);
    QWidget* GetQListItemWidget(ipay::ScenePlaybackType type, QListWidgetItem* item);
    int GetQListItemSize(ipay::ScenePlaybackType type);
    void delete_record_keyboard_by_type(const std::vector<ipay::KeyboardMouseRecordStruct>& recordVector,ipay::ScenePlaybackType type);

signals:
    void start_keyboard_record();
    void hideSettingPage();


public slots:
    void save_keyboard_operation();
    void delete_record_keyboard(ipay::ScenePlaybackType type,int index);
    void init_show();

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
    int keyboard_ui_w = -1;
    int keyboard_ui_h = -1;

};

#endif // CASHREGISTERSETTING_H
