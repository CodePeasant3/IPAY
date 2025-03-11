#include "paymentplatform.h"
#include "./ui_paymentplatform.h"

PaymentPlatform::PaymentPlatform(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PaymentPlatform)
{
    ui->setupUi(this);
    init();
}

PaymentPlatform::~PaymentPlatform()
{
    delete ui;
    exit();
}

void PaymentPlatform::init()
{
    ui ->MainPushButton->setIcon(QIcon(":/Resources/image/MainPlay.png"));
    ui ->MainPushButton->setText("0");
    receiptAction_ = new QAction(QIcon(":/Resources/image/receiptAction.png"),"收款");
    refundActuin_ = new QAction(QIcon(":/Resources/image/refundActuin.png"),"退款");
    detailAction_ = new QAction(QIcon(":/Resources/image/detailAction.png"),"明细");
    settingAction_ = new QAction(QIcon(":/Resources/image/settingAction.png"),"设置");
    exitAction_ = new QAction(QIcon(":/Resources/image/exitAction.png"),"退出");
    pushMenu_ = new QMenu();
    pushMenu_->addAction(receiptAction_);
    pushMenu_->addAction(refundActuin_);
    pushMenu_->addAction(detailAction_);
    pushMenu_->addAction(settingAction_);
    pushMenu_->addAction(exitAction_);
    ui ->MainPushButton->setMenu(pushMenu_);

}

void PaymentPlatform::exit()
{
    delete receiptAction_;
    delete refundActuin_;
    delete detailAction_;
    delete settingAction_;
    delete exitAction_;
    delete pushMenu_;
}

