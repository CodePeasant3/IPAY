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

#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QMutex>
#include <qdebug.h>

// 互斥锁，用于线程安全
static QMutex logMutex;

// 自定义消息处理函数
void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QMutexLocker locker(&logMutex); // 加锁保证线程安全

    // 构建日志消息
    QString logMessage;
    switch (type) {
    case QtDebugMsg:
        logMessage = QString("[DEBUG] %1 (%2:%3, %4)").arg(msg).arg(context.file).arg(context.line).arg(context.function);
        break;
    case QtInfoMsg:
        logMessage = QString("[INFO] %1").arg(msg);
        break;
    case QtWarningMsg:
        logMessage = QString("[WARNING] %1 (%2:%3, %4)").arg(msg).arg(context.file).arg(context.line).arg(context.function);
        break;
    case QtCriticalMsg:
        logMessage = QString("[CRITICAL] %1 (%2:%3, %4)").arg(msg).arg(context.file).arg(context.line).arg(context.function);
        break;
    case QtFatalMsg:
        logMessage = QString("[FATAL] %1 (%2:%3, %4)").arg(msg).arg(context.file).arg(context.line).arg(context.function);
        abort(); // 发生致命错误时终止程序
    }

    // 输出到控制台
    QTextStream(stdout) << logMessage << endl;

    // 输出到文件
    QFile file("application.log");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream logStream(&file);
        logStream << QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss.zzz") << " " << logMessage << endl;
        file.close();
    }

    // 可以添加更多处理，如发送到远程服务器
}

int main(int argc, char *argv[])
{
    // 检查命令行参数，是否需要显示控制台
    bool showConsole = false;
    for (int i = 0; i < argc; ++i) {
        if (QString(argv[i]) == "--console") {
            showConsole = true;
            break;
        }
    }

    // 如果需要显示控制台
    if (showConsole) {
        AllocConsole();
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
    }

    // 安装自定义消息处理函数
    qInstallMessageHandler(customMessageHandler);

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

    QWidget::connect(&cashRegisterKeyboard,&CashRegisterKeyboard::AllowOperation,&paymentPlatform,&PaymentPlatform::EnableOperation);
    QWidget::connect(&collectionMoney,&CollectionMoney::AllowOperation,&paymentPlatform,&PaymentPlatform::EnableOperation);
    QWidget::connect(&keyboardRecordOperation,&KeyboardRecordOperation::AllowOperation,&paymentPlatform,&PaymentPlatform::EnableOperation);
    QWidget::connect(&orderDetails,&OrderDetails::AllowOperation,&paymentPlatform,&PaymentPlatform::EnableOperation);
    QWidget::connect(&playSetting,&PlaySetting::AllowOperation,&paymentPlatform,&PaymentPlatform::EnableOperation);

    return a.exec();
}






