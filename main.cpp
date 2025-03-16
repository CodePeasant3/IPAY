#include "View/paymentplatform.h"
#include <QApplication>
#include "View/PlaySetting.h"
#include "View/cashregisterkeyboard.h"
#include "View/orderdetails.h"
#include "Common/primaryscreen.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PrimaryScreen primaryScreen;
    QRect rect = primaryScreen.GetGeometryScreen();
    PlaySetting playSetting;
    CashRegisterKeyboard cashRegisterKeyboard;
    OrderDetails orderDetails;
    PaymentPlatform paymentPlatform;
    playSetting.resize(rect.width() * 0.4,rect.height() *0.4);
    orderDetails.resize(rect.width() * 0.4,rect.height() *0.4);
    cashRegisterKeyboard.resize(rect.width() * 0.2,rect.height() *0.2);
    paymentPlatform.resize(rect.width() * 0.2,rect.height() *0.1);

    playSetting.hide();
    cashRegisterKeyboard.hide();
    orderDetails.hide();
    paymentPlatform.show();

    CashRegisterKeyboard::connect(&paymentPlatform,&PaymentPlatform::ShowCashKeyboard,&cashRegisterKeyboard,&CashRegisterKeyboard::show);
    CashRegisterKeyboard::connect(&cashRegisterKeyboard,&CashRegisterKeyboard::FinalMoney,&paymentPlatform,&PaymentPlatform::ReceiveMoney);
    CashRegisterKeyboard::connect(&paymentPlatform,&PaymentPlatform::ShowSetting,&playSetting,&PlaySetting::show);
    CashRegisterKeyboard::connect(&paymentPlatform,&PaymentPlatform::ClickExit,&a,&QApplication::quit);
    CashRegisterKeyboard::connect(&paymentPlatform,&PaymentPlatform::ShowDetails,&orderDetails,&OrderDetails::show);

    return a.exec();
}
