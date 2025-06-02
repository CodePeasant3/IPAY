#include "paymentplatform.h"
#include "./ui_paymentplatform.h"

PaymentPlatform::PaymentPlatform(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PaymentPlatform)
{
    ui->setupUi(this);
    this ->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
    this->move(0,0);
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
    ui ->MainPushButton->setStyleSheet("QPushButton {  border: none; } QPushButton::menu-indicator { image: none; }");
    receiptAction_ = new QAction(QIcon(":/Resources/image/receiptAction.png"),"收款");
    refundActuin_ = new QAction(QIcon(":/Resources/image/refundActuin.png"),"退款");
    modifyMoney_ = new  QAction(QIcon(":/Resources/image/modifyMoney.png"),"修改");
    detailAction_ = new QAction(QIcon(":/Resources/image/detailAction.png"),"明细");
    settingAction_ = new QAction(QIcon(":/Resources/image/settingAction.png"),"设置");
    exitAction_ = new QAction(QIcon(":/Resources/image/exitAction.png"),"退出");

    pushMenu_ = new QMenu();
    pushMenu_->addAction(receiptAction_);
    pushMenu_->addAction(refundActuin_);
    pushMenu_->addAction(modifyMoney_);
    pushMenu_->addAction(detailAction_);
    pushMenu_->addAction(settingAction_);
    pushMenu_->addAction(exitAction_);
    ui ->MainPushButton->setMenu(pushMenu_);

    connect(ui->label_money,&ClickableLabel::doubleClicked,this,[=]() {
        emit ShowCashKeyboard();
        this->setEnabled(false);
    });

    connect(receiptAction_, &QAction::triggered, this, [=]() {
//        emit ShowCashKeyboard();
        emit ShowCollecton();
        emit StartModel(1);
        this->setEnabled(false);
        std::shared_ptr<ipay::AllSettingConfig> settingConfig  = ipay::GlobalStatusCommon::instance()->GetAllSettingConfig();
        settingConfig.get()->cash_register_setting.recognition_type = 1;
        ipay::GlobalStatusCommon::instance()->ModifyCashRegisterSettingNotWrite(settingConfig.get()->cash_register_setting);
    });

    connect(refundActuin_, &QAction::triggered, this, [=]() {
        emit ShowCollecton();
        emit StartModel(0);
        this->setEnabled(false);
        std::shared_ptr<ipay::AllSettingConfig> settingConfig  = ipay::GlobalStatusCommon::instance()->GetAllSettingConfig();
        settingConfig.get()->cash_register_setting.recognition_type = 1;
        ipay::GlobalStatusCommon::instance()->ModifyCashRegisterSettingNotWrite(settingConfig.get()->cash_register_setting);
    });
    connect(modifyMoney_, &QAction::triggered, this, [=]() {
        emit ShowCashKeyboard();
        emit StartModel(1);
        this->setEnabled(false);
        std::shared_ptr<ipay::AllSettingConfig> settingConfig  = ipay::GlobalStatusCommon::instance()->GetAllSettingConfig();
        settingConfig.get()->cash_register_setting.recognition_type = 1;
        ipay::GlobalStatusCommon::instance()->ModifyCashRegisterSettingNotWrite(settingConfig.get()->cash_register_setting);
    });

    connect(detailAction_, &QAction::triggered, this, [=]() {
        emit ShowDetails();
        this->setEnabled(false);
    });
    connect(settingAction_, &QAction::triggered, this, [=]() {
        emit ShowSetting();
        this->setEnabled(false);

    });
    connect(exitAction_, &QAction::triggered, this, [=]() {
        emit ClickExit();
    });

}

void PaymentPlatform::exit()
{
    if(receiptAction_)
        delete receiptAction_;
    if(refundActuin_)
        delete refundActuin_;
    if(detailAction_)
        delete detailAction_;
    if(settingAction_)
        delete settingAction_;
    if(exitAction_)
        delete exitAction_;
    if(pushMenu_)
        delete pushMenu_;
}

void PaymentPlatform::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        // 记录鼠标按下时相对于组件的位置
        offset = event->pos();
        mousePressed = true;
    }
    QWidget::mousePressEvent(event);
}

void PaymentPlatform::mouseMoveEvent(QMouseEvent *event)
{
    if (mousePressed && (event->buttons() & Qt::LeftButton)) {
        // 计算鼠标移动的偏移量
        QPoint newPos = event->globalPos() - offset;
        // 更新组件的位置
        move(newPos);
    }
    QWidget::mouseMoveEvent(event);
}

void PaymentPlatform::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        mousePressed = false;
    }
    QWidget::mouseReleaseEvent(event);

}

void PaymentPlatform::ReceiveMoney(std::string moneyNumber)
{
    ui->label_money->setText(QString::fromStdString("¥" + moneyNumber));
}

void PaymentPlatform::EnableOperation()
{
    this->setEnabled(true);
}


