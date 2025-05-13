#include "View/paymentplatform.h"
#include <QApplication>
#include "View/PlaySetting.h"
#include "View/cashregisterkeyboard.h"
#include "View/orderdetails.h"
#include "View/keyboardrecordoperation.h"
#include "Common/primaryscreen.h"
#include <QThread>
#include "Common/globalstatuscommon.h"
#include <QProcess>
#include <QMessageBox>
#include <windows.h>
#include <Shlobj.h>
#include "View/collectionmoney.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    if (!IsUserAnAdmin()) {
//        QString executable_path = QCoreApplication::applicationFilePath();
//        // 以管理员权限重新启动程序
//        SHELLEXECUTEINFOW sei = { sizeof(sei) };
//        sei.lpVerb = L"runas";
//        sei.lpFile = reinterpret_cast<LPCWSTR>(executable_path.utf16());
//        sei.nShow = SW_SHOWNORMAL;

//        if (!ShellExecuteExW(&sei)) {
//            QMessageBox::critical(nullptr, "Error", "Failed to relaunch as administrator.");
//            return 1;
//        }
//        return 0;
//    }


    ipay::GlobalStatusCommon::instance()->ConfigInit();
    ipay::PrimaryScreen primaryScreen;
    QRect rect = primaryScreen.GetGeometryScreen();
    PlaySetting playSetting;
    CashRegisterKeyboard cashRegisterKeyboard;
    OrderDetails orderDetails(ipay::GlobalStatusCommon::instance()->db_ops);
    CollectionMoney collectionMoney;
    PaymentPlatform paymentPlatform;
    KeyboardRecordOperation keyboardRecordOperation;

    Qt::WindowFlags playSettingFlags = playSetting.windowFlags();
    playSetting.resize(rect.width() * 0.4,rect.height() *0.4);
    playSetting.setWindowFlags(playSettingFlags &~ Qt::WindowMinMaxButtonsHint);
    playSetting.setFixedSize(rect.width() * 0.4,rect.height() *0.4);
    playSetting.setWindowTitle("Setting");


    orderDetails.resize(rect.width() * 0.4,rect.height() *0.4);
    Qt::WindowFlags orderDetailsFlags = orderDetails.windowFlags();
    orderDetails.setWindowFlags(orderDetailsFlags &~ Qt::WindowMinMaxButtonsHint);
    orderDetails.setFixedSize(rect.width() * 0.4,rect.height() *0.4);
    orderDetails.setWindowTitle("OrderList");

    cashRegisterKeyboard.resize(rect.width() * 0.2,rect.height() *0.2);
    paymentPlatform.resize(rect.width() * 0.2,rect.height() *0.1);
    keyboardRecordOperation.resize(rect.width() * 0.4,rect.height() *0.2);


    paymentPlatform.setWindowFlags(paymentPlatform.windowFlags() | Qt::WindowStaysOnTopHint);
    keyboardRecordOperation.setWindowFlags(keyboardRecordOperation.windowFlags() | Qt::WindowStaysOnTopHint);

    playSetting.hide();
    cashRegisterKeyboard.hide();
    orderDetails.hide();
    keyboardRecordOperation.hide();
    collectionMoney.hide();
    paymentPlatform.show();


    QWidget::connect(&collectionMoney,&CollectionMoney::receiveFlags,&cashRegisterKeyboard,&CashRegisterKeyboard::ReceiveQRInfo);
    QWidget::connect(&cashRegisterKeyboard,&CashRegisterKeyboard::SendMoneyNum,&collectionMoney,&CollectionMoney::transferMoney);

    QWidget::connect(&collectionMoney,&CollectionMoney::showKeyboard,&cashRegisterKeyboard,&CashRegisterKeyboard::show);
    QWidget::connect(&collectionMoney,&CollectionMoney::showKeyboard,&collectionMoney,&CollectionMoney::hide);
    QWidget::connect(&cashRegisterKeyboard,&CashRegisterKeyboard::ShowCollection,&collectionMoney,&CollectionMoney::show);
    QWidget::connect(&cashRegisterKeyboard,&CashRegisterKeyboard::ShowCollection,&cashRegisterKeyboard,&CashRegisterKeyboard::hide);


    QWidget::connect(&paymentPlatform,&PaymentPlatform::ShowCollecton,&collectionMoney,&CollectionMoney::show);
    QWidget::connect(&paymentPlatform,&PaymentPlatform::ShowCollecton,&cashRegisterKeyboard,&CashRegisterKeyboard::hide);
    QWidget::connect(&paymentPlatform,&PaymentPlatform::ShowCashKeyboard,&cashRegisterKeyboard,&CashRegisterKeyboard::show);
    QWidget::connect(&paymentPlatform,&PaymentPlatform::ShowCashKeyboard,&collectionMoney,&CollectionMoney::hide);

    QWidget::connect(&paymentPlatform,&PaymentPlatform::StartModel,&collectionMoney,&CollectionMoney::operationShow);
    QWidget::connect(&paymentPlatform,&PaymentPlatform::StartModel,&cashRegisterKeyboard,&CashRegisterKeyboard::operationShow);


    QWidget::connect(&cashRegisterKeyboard,&CashRegisterKeyboard::FinalMoney,&paymentPlatform,&PaymentPlatform::ReceiveMoney);
    QWidget::connect(&paymentPlatform,&PaymentPlatform::ShowSetting,&playSetting,&PlaySetting::show);
    QWidget::connect(&paymentPlatform,&PaymentPlatform::ClickExit,&a,&QApplication::quit);
    QWidget::connect(&paymentPlatform,&PaymentPlatform::ShowDetails,&orderDetails,&OrderDetails::show);

    QWidget::connect(&playSetting,&PlaySetting::start_keyboard_record,&playSetting,&PlaySetting::hide);
    QWidget::connect(&playSetting,&PlaySetting::start_keyboard_record,&keyboardRecordOperation,&KeyboardRecordOperation::show);
    QWidget::connect(&playSetting,&PlaySetting::start_keyboard_record,
                     &keyboardRecordOperation,&KeyboardRecordOperation::StartRecordKeyboard,Qt::DirectConnection);
    QWidget::connect(&keyboardRecordOperation,&KeyboardRecordOperation::stop_keyboard_record,
                     &keyboardRecordOperation,&KeyboardRecordOperation::hide);
    return a.exec();
}






