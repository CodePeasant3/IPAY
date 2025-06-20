#include "cashregisterkeyboard.h"
#include "qdebug.h"
#include "ui_cashregisterkeyboard.h"
#include <QTimer>
#include <Common/logging.h>
#include <Common/dbops.h>
#include <Common/httpsrequest.h>

//std::vector<std::string> CashRegisterKeyboard::money_vector_;
CashRegisterKeyboard::CashRegisterKeyboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CashRegisterKeyboard)
{
    ui->setupUi(this);
//    Init();
}

CashRegisterKeyboard::~CashRegisterKeyboard()
{
//    if(type == ipay::KeyboardOperationType::COLLECTION ){
//    }
    future_thread.get();
    if(process_timer_){
        process_timer_->stop();
        delete process_timer_;
        process_timer_ = nullptr;
    }
    delete ui;
}

void CashRegisterKeyboard::Init(const ipay::KeyboardOperationType type,  DBOps* db_ptr, HttpsRequest* request_ptr)
{
    this->m_db_ops = db_ptr;
    this->m_request = request_ptr;

    QRect rect = ipay::GlobalStatusCommon::instance()->GetScreenScope();
    this->resize(rect.width() * 0.2,rect.height() *0.2);
    self_type_ = type;
    this->setWindowFlags(this->windowFlags() &~ Qt::WindowMinMaxButtonsHint);//禁止最大和最小化
    ui->widget_3->hide();
    connect(ui ->label_keyboard,&ClickableLabel::clicked,this,&CashRegisterKeyboard::KeyboardShow);
    money_vector_.push_back("0");
    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
    this->setWindowTitle("收款");
    connect(ui->pushButton_cash1,&QPushButton::clicked,this,&CashRegisterKeyboard::ClickReceive);
    connect(ui->pushButton_cash2,&QPushButton::clicked,this,&CashRegisterKeyboard::ClickReceive);

    if(self_type_ == ipay::KeyboardOperationType::COLLECTION ){
        if(!process_timer_){
            process_timer_ = new QTimer();
            process_timer_->setInterval(1000);
            QObject::connect(process_timer_, &QTimer::timeout, [this]() {
                if(ipay::GlobalStatusCommon::instance()->GetAllSettingConfig()->cash_register_setting.is_hide){
                    return;
                }
                if(ipay::GlobalStatusCommon::instance()->GetAllSettingConfig()->cash_register_setting.recognition_type == 0){
                    modifyMoneySlot();
                }

            });
            process_timer_->start();
        }
        future_thread =
            std::async(std::launch::async, &ipay::GlobalStatusCommon::WhileDetect, ipay::GlobalStatusCommon::instance()) ;
    }
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

int CashRegisterKeyboard::MoneyBack()
{
    qrStr_; // QR 条码  需要数据库拿到对应金额

    return 0;
}

bool CashRegisterKeyboard::isValidNumber(const QString& str)
{
    QRegularExpression re("^[0-9.]+$");
    return re.match(str).hasMatch();
}

void CashRegisterKeyboard::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_0:
        case Qt::Key_1:
        case Qt::Key_2:
        case Qt::Key_3:
        case Qt::Key_4:
        case Qt::Key_5:
        case Qt::Key_6:
        case Qt::Key_7:
        case Qt::Key_8:
        case Qt::Key_9:
            ModifyMoney(QString::number(event->key() - Qt::Key_0).toStdString());
            event->accept();
            break;
        case Qt::Key_Period:
        case Qt::Key_Comma:
            ModifyMoney(".");
            break;
        case Qt::Key_Backspace:
             DeleteMoney();
            event->accept();
            break;
        case Qt::Key_Return:
        case Qt::Key_Enter:
            ClickReceive();
            event->accept();
            break;
        default:
            QWidget::keyPressEvent(event);
            break;
    }

}

void CashRegisterKeyboard::KeyboardShow()
{

   isShow_ ? ui->widget_3->hide() : ui->widget_3->show();
   isShow_ ? ui->pushButton_cash1->show() : ui->pushButton_cash1->hide();
   isShow_ ? ui->label_keyboard->setText("显示键盘") : ui->label_keyboard->setText("隐藏键盘");
   isShow_ = !isShow_;

}

void CashRegisterKeyboard::ChangeMonet()
{
    money_result_ = "";
    for (const auto& str : money_vector_) {
        money_result_ += str;
    }

    ui->label_money ->setText(QString::fromStdString("¥"+money_result_));
    ui->label_money->setStyleSheet("color: rgb(255, 255, 255);");
    emit FinalMoney(money_result_);
}

void CashRegisterKeyboard::ReceiveQRInfo(QString qrStr)
{
    qInfo(IPAY) << ">>>>> refund code: " << qrStr;
    QString refund_amount; // 订单金额, 单位 分
    bool exists = m_db_ops->queryPayOrderID(qrStr, refund_amount);
    if(!exists) {
        QMessageBox::warning(this,"错误","未找到相应支付订单!");
        return;
    }
    if(refund_amount.isEmpty()){
        QMessageBox::warning(this,"错误","支付订单消息错误,请联系运维!");
        return;
    }

    // qInfo(IPAY) << "0620 debug: " << refund_amount.toInt();
    releiveMoneyStr(QString::number(refund_amount.toInt() / 100.0).toStdString());
    // 存在, 进入退款流程
    // TODO: 弹出密码框
    m_request->refund(qrStr.toStdString(), refund_amount.toStdString());


    qrStr_ = qrStr;
}

void CashRegisterKeyboard::operationShow(int flags)
{
    if(flags == 0){
        ui ->pushButton_cash2->setText("退款");
        ui ->pushButton_cash1 ->setText("退款");
    }else{
        ui ->pushButton_cash2->setText("收款");
        ui ->pushButton_cash1 ->setText("收款");
    }
    flags_ = flags;
}

void CashRegisterKeyboard::ClickReceive()
{
    if(self_type_ == ipay::KeyboardOperationType::MODIAY){
        modifyMoneySlot();
        return;
    }

    if(money_result_.empty()){
        QMessageBox::warning(this,"警告","请设置金额后操作");
        return;
    }
    if(flags_ != 0){
        emit ShowCollection();
        return;
    }
    MoneyBack();
}

void CashRegisterKeyboard::closeEvent(QCloseEvent *event){
    event->accept();
    std::shared_ptr<ipay::AllSettingConfig> settingConfig  = ipay::GlobalStatusCommon::instance()->GetAllSettingConfig();
    settingConfig.get()->cash_register_setting.is_hide = true;
    ipay::GlobalStatusCommon::instance()->ModifyCashRegisterSettingNotWrite(settingConfig.get()->cash_register_setting);
    emit AllowOperation();
}

void CashRegisterKeyboard::ModifyMoney(std::string number)
{
    qInfo(IPAY) << "ModifyMoney in";
    if(money_vector_.size() >= 8){
        qInfo(IPAY) << "ModifyMoney: money_vector size >= 8";
        return;
    }
    point_bit +=1;
    if(!isDecimalPoint_){
        point_bit = 0;
    }
    if((isDecimalPoint_ && number == ".") || point_bit > 2){
        qInfo(IPAY) << "ModifyMoney: number == . || point_bit > 8";
        return;
    }
    if(number == "."){
        isDecimalPoint_ = true;
    }
    if(money_vector_.back() == "0" && money_vector_.size() == 1){
        if(number != "."){
            money_vector_.pop_back();
        }
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
        std::string lastElement = money_vector_.back();
        if(lastElement == "."){
             isDecimalPoint_ = false;
        }
        money_vector_.pop_back();
    }
    ChangeMonet();
}

void CashRegisterKeyboard::killAlgoThread() {
    ipay::GlobalStatusCommon::instance()->unsetOK();
}

void CashRegisterKeyboard::saveLastQR(const ipay::QRDetailStruct &qr_struct)
{
    lastQRDetail_ = qr_struct;

}

void CashRegisterKeyboard::modifyMoneySlot()
{
    std::string result = ipay::GlobalStatusCommon::instance()->PictureProcess();
    if(result.empty()){
        return;
    }
    if(!isValidNumber(QString::fromStdString(result))){
        QMessageBox::warning(this,"错误","识别金额错误!");
        return;
    }
    QString q_result(result.c_str());
    releiveMoneyStr(QString::number(q_result.toInt() / 100.0).toStdString());

    ChangeMonet();
}

void CashRegisterKeyboard::releiveMoneyStr(const std::string &moneyStr)
{
    money_vector_.clear();
    qInfo(IPAY) << "moneyStr: " << moneyStr.c_str();
    point_bit = 0;
    isDecimalPoint_ = false;
    for (char c : moneyStr) {
        qInfo(IPAY) << "monyStr for: " << c;
        ModifyMoney(std::string(1, c));
    }

}




