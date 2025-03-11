#include "commonsetting.h"
#include "ui_commonsetting.h"

CommonSetting::CommonSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommonSetting)
{
    ui->setupUi(this);
}

CommonSetting::~CommonSetting()
{
    delete ui;
}
