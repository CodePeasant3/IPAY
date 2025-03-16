#include "View/paymentplatform.h"
#include "Utils/clickablelabel.h"
#include <QApplication>
#include "View/PlaySetting.h"
#include "View/cashregisterkeyboard.h""
#include "View/orderdetails.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PlaySetting playSetting;
    CashRegisterKeyboard cashRegisterKeyboard;
    OrderDetails orderDetails;
    playSetting.hide();
    cashRegisterKeyboard.hide();
    orderDetails.hide();
    PaymentPlatform paymentPlatform;
    paymentPlatform.show();

    CashRegisterKeyboard::connect(&paymentPlatform,&PaymentPlatform::ShowCashKeyboard,&cashRegisterKeyboard,&CashRegisterKeyboard::show);
    CashRegisterKeyboard::connect(&paymentPlatform,&PaymentPlatform::ShowSetting,&playSetting,&PlaySetting::show);
    CashRegisterKeyboard::connect(&paymentPlatform,&PaymentPlatform::ClickExit,&a,&QApplication::quit);
    CashRegisterKeyboard::connect(&paymentPlatform,&PaymentPlatform::ShowDetails,&orderDetails,&OrderDetails::show);

    return a.exec();
}
