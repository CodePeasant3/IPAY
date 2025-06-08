#include "collectionmoney.h"
#include "qevent.h"
#include "ui_collectionmoney.h"
#include "QDebug"
#include "../Common/primaryscreen.h"
#include <QRegExpValidator>
#include <QRegExp>


CollectionMoney::CollectionMoney(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CollectionMoney)
{
    ui->setupUi(this);
    Init();
}

CollectionMoney::~CollectionMoney()
{
    delete ui;
}

void CollectionMoney::Init()
{

    QRect rect = ipay::GlobalStatusCommon::instance()->GetScreenScope();
    this->resize(rect.width() * 0.2,rect.height() *0.4);

    QPixmap QRCodePixmap("://Resources/image/QRCode.png");
    int labelIconWidth = rect.width() * 0.12;

    double widthRatio = (double)labelIconWidth / QRCodePixmap.width();
    int scaledQRHeight = QRCodePixmap.height() * widthRatio;
    QPixmap scaledPixmap = QRCodePixmap.scaled(
        labelIconWidth, scaledQRHeight,
        Qt::KeepAspectRatio,
        Qt::SmoothTransformation
    );
    ui->label_icon->setPixmap(scaledPixmap);
    ui->label_icon->setAlignment(Qt::AlignCenter);
    FuncationShow("收款","录入顾客手机支付凭证条码","收款");

    // 这里new一下, 会有溢出的问题吗? 无所谓了
    QRegExp regex("^[a-zA-Z0-9]+$");
    QRegExpValidator *validator = new QRegExpValidator(regex, ui->lineEdit_qr);
    ui ->lineEdit_qr->setValidator(validator);
    ui ->lineEdit_qr->setPlaceholderText("请输入订单编号");

    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
    this->setWindowFlags(this->windowFlags() &~ Qt::WindowMinMaxButtonsHint);//禁止最大和最小化
}

void CollectionMoney::FuncationShow(std::string titleStr, std::string remindStr,std::string functionStr)
{
    this->setWindowTitle(titleStr.c_str());
    ui->label_remind->setText(QString::fromStdString(remindStr));
    ui->label_title->setText(QString::fromStdString(titleStr));
    ui->label_remind->setAlignment(Qt::AlignCenter);
    ui->label_title->setAlignment(Qt::AlignCenter);
    ui->pushButton_qr->setText(QString::fromStdString(functionStr));
}

void CollectionMoney::ReceiveMoney()
{
    receiveMoney_; // 金额
    QString qtStr = ui ->lineEdit_qr->text();// 二维码

}

void CollectionMoney::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
            on_pushButton_qr_clicked();
            event->accept();
        } else {
            QWidget::keyPressEvent(event);
        }
}

void CollectionMoney::operationShow(int flags)
{
    funcationFlags_ = flags;
    if(flags == 0){
        FuncationShow("退款","录入顾客手机收款码","查询");
    }else{
        FuncationShow("收款","录入顾客手机支付凭证条码","收款");
    }
}

void CollectionMoney::transferMoney(std::string money)
{
    receiveMoney_ = money;
}

void CollectionMoney::on_pushButton_qr_clicked()
{
    QString qtStr = ui ->lineEdit_qr->text();
    if(qtStr.isEmpty()){
        QMessageBox::warning(this,"错误","请输入条纹码信息!");
        return;
    }
    if(funcationFlags_ == 0){
        emit receiveFlags(qtStr);
        emit showKeyboard();
        return;
    }
    ReceiveMoney();


}


void CollectionMoney::closeEvent(QCloseEvent *event) {
    ui ->lineEdit_qr->clear();
    event->accept();
    std::shared_ptr<ipay::AllSettingConfig> settingConfig  = ipay::GlobalStatusCommon::instance()->GetAllSettingConfig();
    settingConfig.get()->cash_register_setting.is_hide = true;
    ipay::GlobalStatusCommon::instance()->ModifyCashRegisterSettingNotWrite(settingConfig.get()->cash_register_setting);
    emit AllowOperation();
}
