#include "cashregistersetting.h"
#include "ui_cashregistersetting.h"

CashRegisterSetting::CashRegisterSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CashRegisterSetting)
{
    ui->setupUi(this);
}

CashRegisterSetting::~CashRegisterSetting()
{
    delete ui;
}
