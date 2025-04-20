    #include "cashregisterkeyboard.h"
#include "qdebug.h"
#include "ui_cashregisterkeyboard.h"
std::vector<std::string> CashRegisterKeyboard::money_vector_;
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
    connect(ui ->label_keyboard,&ClickableLabel::clicked,this,&CashRegisterKeyboard::KeyboardShow);
    money_vector_.push_back("0");

}

void CashRegisterKeyboard::KeyboardShow()
{

   isShow_ ? ui->widget_3->hide() : ui->widget_3->show();
   isShow_ ? ui->pushButton_cash1->show() : ui->pushButton_cash1->hide();
   isShow_ ? ui->label_keyboard->setText("显示键盘") : ui->label_keyboard->setText("隐藏键盘");
   isShow_ = !isShow_;
   connect(ui->pushButton_0, &QPushButton::clicked, this, [=]() { ModifyMoney("0"); });
   connect(ui->pushButton_1, &QPushButton::clicked, this, [=]() { ModifyMoney("1"); });
   connect(ui->pushButton_2, &QPushButton::clicked, this, [=]() { ModifyMoney("2"); });
   connect(ui->pushButton_3, &QPushButton::clicked, this, [=]() { ModifyMoney("3"); });
   connect(ui->pushButton_4, &QPushButton::clicked, this, [=]() { ModifyMoney("4"); });
   connect(ui->pushButton_5, &QPushButton::clicked, this, [=]() { ModifyMoney("5"); });
   connect(ui->pushButton_6, &QPushButton::clicked, this, [=]() { ModifyMoney("6"); });
   connect(ui->pushButton_7, &QPushButton::clicked, this, [=]() { ModifyMoney("7"); });
   connect(ui->pushButton_8, &QPushButton::clicked, this, [=]() { ModifyMoney("8"); });
   connect(ui->pushButton_9, &QPushButton::clicked, this, [=]() { ModifyMoney("9"); });
   connect(ui->pushButton_point, &QPushButton::clicked, this, [=]() { ModifyMoney("."); });
   connect(ui->pushButton_X, &QPushButton::clicked, this, [=]() { DeleteMoney(); });

}

void CashRegisterKeyboard::ChangeMonet()
{
    std::string money_result;
    for (const auto& str : money_vector_) {
        money_result += str;
    }
    ui->label_money ->setText(QString::fromStdString("¥"+money_result));
    emit FinalMoney(money_result);
}

void CashRegisterKeyboard::ModifyMoney(std::string number)
{
    if(money_vector_.back() == "0" && money_vector_.size() == 1){
        money_vector_.pop_back();
        money_vector_.push_back(number);
    }else{
        money_vector_.push_back(number);
    }
    ChangeMonet();
}

void CashRegisterKeyboard::DeleteMoney()
{
    if(money_vector_.size() == 1){
        money_vector_.pop_back();
        money_vector_.push_back("0");
    }else{
        money_vector_.pop_back();
    }
    ChangeMonet();
}

