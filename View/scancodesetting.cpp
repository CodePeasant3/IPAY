#include "scancodesetting.h"
#include "ui_scancodesetting.h"

ScanCodeSetting::ScanCodeSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScanCodeSetting)
{
    ui->setupUi(this);
}

ScanCodeSetting::~ScanCodeSetting()
{
    delete ui;
}
