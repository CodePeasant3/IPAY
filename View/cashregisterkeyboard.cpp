#include "cashregisterkeyboard.h"
#include "ui_cashregisterkeyboard.h"

CashRegisterKeyboard::CashRegisterKeyboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CashRegisterKeyboard)
{
    ui->setupUi(this);
    Init();
}

CashRegisterKeyboard::~CashRegisterKeyboard()
{
    delete ui;
}

void CashRegisterKeyboard::Init()
{
    ui->widget_3->hide();
    connect(ui ->label_keyboard,&ClickableLabel::clicked,this,&CashRegisterKeyboard::keyboardShow);
}

void CashRegisterKeyboard::keyboardShow()
{

   isShow_ ? ui->widget_3->hide() : ui->widget_3->show();
   isShow_ ? ui->pushButton_cash1->show() : ui->pushButton_cash1->hide();
   isShow_ = !isShow_;
}
