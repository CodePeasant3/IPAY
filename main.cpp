#include "View/paymentplatform.h"
#include "Utils/clickablelabel.h"
#include <QApplication>
#include "View/PlaySetting.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    PlaySetting p;
//    p.show();
    PaymentPlatform w;
    w.show();
    return a.exec();
}
