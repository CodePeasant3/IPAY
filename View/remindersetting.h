#ifndef REMINDERSETTING_H
#define REMINDERSETTING_H

#include <QWidget>
#include "../Common/globalstatuscommon.h"

namespace Ui {
class ReminderSetting;
}

class ReminderSetting : public QWidget
{
    Q_OBJECT

public:
    explicit ReminderSetting(QWidget *parent = nullptr);
    ~ReminderSetting();

private slots:
    void on_pushButton_enable_voice_clicked();

private:
    Ui::ReminderSetting *ui;
    ipay::RemindSettingStruct remind_setting_struct_;
};

#endif // REMINDERSETTING_H
