#include "remindersetting.h"
#include "ui_remindersetting.h"

ReminderSetting::ReminderSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReminderSetting)
{
    ui->setupUi(this);
}

ReminderSetting::~ReminderSetting()
{
    delete ui;
}

void ReminderSetting::on_pushButton_enable_voice_clicked()
{
    remind_setting_struct_.voice_remoid = !remind_setting_struct_.voice_remoid;
    remind_setting_struct_.voice_remoid == true ? ui ->pushButton_enable_voice->setText("关闭") :
                                               ui ->pushButton_enable_voice->setText("开启");

}

