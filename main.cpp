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
    OrderDetails orderDetails;
    PaymentPlatform paymentPlatform;
    KeyboardRecordOperation keyboardRecordOperation;

    playSetting.resize(rect.width() * 0.4,rect.height() *0.4);
    orderDetails.resize(rect.width() * 0.4,rect.height() *0.4);
    cashRegisterKeyboard.resize(rect.width() * 0.2,rect.height() *0.2);
    paymentPlatform.resize(rect.width() * 0.2,rect.height() *0.1);
    keyboardRecordOperation.resize(rect.width() * 0.4,rect.height() *0.2);


    paymentPlatform.setWindowFlags(paymentPlatform.windowFlags() | Qt::WindowStaysOnTopHint);
    keyboardRecordOperation.setWindowFlags(keyboardRecordOperation.windowFlags() | Qt::WindowStaysOnTopHint);

    playSetting.hide();
    cashRegisterKeyboard.hide();
    orderDetails.hide();
    keyboardRecordOperation.hide();
    paymentPlatform.show();



    QWidget::connect(&paymentPlatform,&PaymentPlatform::ShowCashKeyboard,&cashRegisterKeyboard,&CashRegisterKeyboard::show);
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






