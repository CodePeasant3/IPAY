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
