#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QMutex>
#include <qdebug.h>

#include <QLoggingCategory>
#include <logging.h>

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
    // 在创建任何 Qt 对象之前安装消息处理函数
    qInstallMessageHandler(customMessageHandler);
    loadLoggingRulesFromFile("config.ini");

    QCoreApplication a(argc, argv);

    // 使用 Qt 的日志宏测试
    qDebug(IPAY) << "这是一条调试信息";
    qInfo(IPAY) << "这是一条普通信息";
    qWarning(IPAY) << "这是一条警告信息";
    qCritical(IPAY) << "这是一条严重错误信息";
    // qFatal("这是一条致命错误信息"); // 这会导致程序终止

    return a.exec();
}
