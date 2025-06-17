//
#include <QApplication>
#include "View/paymentplatform.h"
#include "View/PlaySetting.h"
#include "View/cashregisterkeyboard.h"
#include "View/orderdetails.h"
#include "View/keyboardrecordoperation.h"
#include "Common/primaryscreen.h"
#include "Common/globalstatuscommon.h"
#include "View/collectionmoney.h"
#include "Common/jsonoperationcommon.h"

#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QMutex>
#include <qdebug.h>
#include <QLoggingCategory>
#include <QKeyEvent>
#include <Common/globalkeyfilter.h>
#include <Common/dbops.h>
#include <Common/httpsrequest.h>
#include "Common/keyboardoperation.h"

// 互斥锁，用于线程安全
static QMutex logMutex;

// 自定义消息处理函数
void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QMutexLocker locker(&logMutex); // 加锁保证线程安全
    const QString& now = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss.zzz");
    // 构建日志消息
    QString logMessage;
    switch (type) {
    case QtDebugMsg:
        logMessage = QString("%5 [DEBUG] %1 (%2:%3, %4)").arg(msg).arg(context.file).arg(context.line).arg(context.function).arg(now);
        break;
    case QtInfoMsg:
        logMessage = QString("%5 [INFO] %1 (%2:%3, %4)").arg(msg).arg(context.file).arg(context.line).arg(context.function).arg(now);
        break;
    case QtWarningMsg:
        logMessage = QString("%5 [WARNING] %1 (%2:%3, %4)").arg(msg).arg(context.file).arg(context.line).arg(context.function).arg(now);
        break;
    case QtCriticalMsg:
        logMessage = QString("%5 [CRITICAL] %1 (%2:%3, %4)").arg(msg).arg(context.file).arg(context.line).arg(context.function).arg(now);
        break;
    case QtFatalMsg:
        logMessage = QString("%5 [FATAL] %1 (%2:%3, %4)").arg(msg).arg(context.file).arg(context.line).arg(context.function).arg(now);
        abort(); // 发生致命错误时终止程序
    }

    // 输出到控制台
    QTextStream(stdout) << logMessage << endl;

    // 输出到文件
    QFile file("application.log");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream logStream(&file);
        logStream << logMessage << endl;
        file.close();
    }

    // 可以添加更多处理，如发送到远程服务器
}

// 设置日志等级
void loadLoggingRulesFromFile(const QString& filePath) {
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString rules = in.readAll();
        QLoggingCategory::setFilterRules(rules);
        file.close();
    }
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
    loadLoggingRulesFromFile("config.ini");

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
    DBOps db_ops;
    int ret = db_ops.init();
    if(ret) {
        qWarning() << "DB ops init failed";
    }

    HttpsRequest request;
    QSettings settings("config.ini", QSettings::IniFormat);
    request.init(settings, &db_ops);

    GlobalEnterHook enterHook(&request);
    // 启动监听
    if (enterHook.startHook()) {
        qDebug() << "全局回车键监听已启动";
    }
    else
    {
        qDebug() << "无法启动全局回车键监听！可能缺少管理员权限。";
    }

    ipay::GlobalStatusCommon::instance()->ConfigInit();
//    std::vector<ipay::KeyboardMouseRecordStruct> aaaa = ipay::GlobalStatusCommon::instance()
//            ->GetFinshKeyboardMouseList(ipay::ScenePlaybackType::CALLBACKPAYDONE);
//    ipay::KeyboardOperation  operationTest;
//    operationTest.OperationKeyboard(aaaa);
//    if(1 == 1){
//        return -1;
//    }



    QRect rect =  ipay::GlobalStatusCommon::instance()->GetScreenScope();
    PlaySetting playSetting;
    CashRegisterKeyboard cashRegisterKeyboard;
    CashRegisterKeyboard cashKeyboardModiay;
    OrderDetails orderDetails(db_ops);
    CollectionMoney collectionMoney;
    PaymentPlatform paymentPlatform;
    KeyboardRecordOperation keyboardRecordOperation;

    cashRegisterKeyboard.Init(ipay::KeyboardOperationType::COLLECTION, &db_ops, &request);
    cashKeyboardModiay.Init(ipay::KeyboardOperationType::MODIAY, &db_ops, &request);

    paymentPlatform.resize(rect.width() * 0.2,rect.height() *0.1);
    keyboardRecordOperation.resize(rect.width() * 0.4,rect.height() *0.2);


    paymentPlatform.setWindowFlags(paymentPlatform.windowFlags() | Qt::WindowStaysOnTopHint);
    keyboardRecordOperation.setWindowFlags(keyboardRecordOperation.windowFlags() | Qt::WindowStaysOnTopHint);
    playSetting.hide();
    cashKeyboardModiay.hide();
    cashRegisterKeyboard.hide();
    orderDetails.hide();
    keyboardRecordOperation.hide();
    collectionMoney.hide();
    paymentPlatform.show();

    // 识别到收款码
    QWidget::connect(&enterHook,&GlobalEnterHook::paymentQR,&cashRegisterKeyboard,&CashRegisterKeyboard::saveLastQR);
    QWidget::connect(&enterHook,&GlobalEnterHook::paymentQR,&cashKeyboardModiay,&CashRegisterKeyboard::saveLastQR);


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

    QWidget::connect(&paymentPlatform,&PaymentPlatform::ShowCashKeyboardModify,&cashKeyboardModiay,&CashRegisterKeyboard::show);
    QWidget::connect(&paymentPlatform,&PaymentPlatform::ShowCashKeyboardModify,&cashKeyboardModiay,&CashRegisterKeyboard::modifyMoneySlot);

    QWidget::connect(&paymentPlatform,&PaymentPlatform::StartModel,&collectionMoney,&CollectionMoney::operationShow);
    QWidget::connect(&paymentPlatform,&PaymentPlatform::StartModel,&cashRegisterKeyboard,&CashRegisterKeyboard::operationShow);
    QWidget::connect(&cashRegisterKeyboard,&CashRegisterKeyboard::FinalMoney,&paymentPlatform,&PaymentPlatform::ReceiveMoney);
    QWidget::connect(&paymentPlatform,&PaymentPlatform::ShowSetting,&playSetting,&PlaySetting::show);
    QWidget::connect(&paymentPlatform,&PaymentPlatform::ClickExit,&a,&QApplication::quit);
    QWidget::connect(&paymentPlatform,&PaymentPlatform::ShowDetails,&orderDetails,&OrderDetails::show);
    QWidget::connect(&paymentPlatform,&PaymentPlatform::ShowDetails,&orderDetails,&OrderDetails::refresh);
    QWidget::connect(&playSetting,&PlaySetting::start_keyboard_record,&playSetting,&PlaySetting::hide);
    QWidget::connect(&playSetting,&PlaySetting::start_keyboard_record,&keyboardRecordOperation,&KeyboardRecordOperation::show);
    QWidget::connect(&playSetting,&PlaySetting::start_keyboard_record,
                     &keyboardRecordOperation,&KeyboardRecordOperation::StartRecordKeyboard,Qt::DirectConnection);
    QWidget::connect(&keyboardRecordOperation,&KeyboardRecordOperation::stop_keyboard_record,
                     &keyboardRecordOperation,&KeyboardRecordOperation::hide);
    QWidget::connect(&keyboardRecordOperation,&KeyboardRecordOperation::stop_keyboard_record,
                     &playSetting,&PlaySetting::show);
    QWidget::connect(&keyboardRecordOperation,&KeyboardRecordOperation::stop_keyboard_record,
                     &playSetting,&PlaySetting::stop_record_keyboard);

    QWidget::connect(&cashRegisterKeyboard,&CashRegisterKeyboard::AllowOperation,&paymentPlatform,&PaymentPlatform::EnableOperation);
    QWidget::connect(&cashKeyboardModiay,&CashRegisterKeyboard::AllowOperation,&paymentPlatform,&PaymentPlatform::EnableOperation);
    QWidget::connect(&collectionMoney,&CollectionMoney::AllowOperation,&paymentPlatform,&PaymentPlatform::EnableOperation);
    QWidget::connect(&keyboardRecordOperation,&KeyboardRecordOperation::AllowOperation,&paymentPlatform,&PaymentPlatform::EnableOperation);
    QWidget::connect(&orderDetails,&OrderDetails::AllowOperation,&paymentPlatform,&PaymentPlatform::EnableOperation);
    QWidget::connect(&playSetting,&PlaySetting::AllowOperation,&paymentPlatform,&PaymentPlatform::EnableOperation);

    QObject::connect(&a, &QCoreApplication::aboutToQuit, &cashRegisterKeyboard, &CashRegisterKeyboard::killAlgoThread);

    return a.exec();
}






