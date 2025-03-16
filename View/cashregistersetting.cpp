#include "cashregistersetting.h"
#include "ui_cashregistersetting.h"

CashRegisterSetting::CashRegisterSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CashRegisterSetting)
{
    ui->setupUi(this);
    Init();
}

CashRegisterSetting::~CashRegisterSetting()
{
    delete ui;
}

void CashRegisterSetting::Init()
{

//ui ->pushButton_save ->setStyleSheet("QPushButton {border-radius: 3%;}");

}
//开始录制
void CashRegisterSetting::on_pushButton_6_clicked()
{

}

// 设置识别区域
void CashRegisterSetting::on_pushButton_3_clicked()
{

}

