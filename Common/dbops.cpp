#include "dbops.h"
#include <iostream>
#include <qlogging.h>
#include <QSqlQuery>
#include <QVariant>
#include <QTime>
#include "logging.h"

int DBOps::init() {
    m_db = QSqlDatabase::addDatabase("QSQLITE", "iPayOrderList");
    m_db.setHostName("localhost");  //数据库主机名
    m_db.setDatabaseName("ipay.db");   //数据库名
    if(!m_db.open()) {
        qCritical(IPAY) << "DB not opened";
        return -1;
    }
    qInfo(IPAY) << "db is open: " << m_db.isOpen();
    QSqlQuery query(m_db);
    this->createTable(query);
    this->cleanOldData(query);

    this->insertData("00000", 2, "202505110011", "200", 1);
    return 0;
}

void DBOps::final() {
    m_db.close();
    return;
}

// id 主键
// orderid 订单号
// type 订单类型: 1-付款 2-退款
// amount 金额 单位分
// status 状态 1-完成 2-未完成
// created_at 订单生成时间
// time 订单生成时间


int DBOps::createTable(QSqlQuery& query) {
    QString sql =
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "orderid TEXT UNIQUE, "
        "type INTEGER NOT NULL, "
        "amount TEXT NOT NULL, "
        "status INTEGER NOT NULL, "
        "created_at DATETIME DEFAULT CURRENT_TIMESTAMP, "
        "time TEXT NOT NULL "
        ")";

    if (!query.exec(sql)) {
        qCritical(IPAY) << "create table failed";
        return -1;
    }

    qInfo(IPAY) << "crate table success";
    return 0;
}

bool DBOps::insertData(QString pay_order_id,
                       int type,
                       QString time,
                       QString amount,
                       int status) {
    QSqlQuery query(m_db);
    QString localTimeStr = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    QString sql_cmd_str =
        "INSERT OR IGNORE INTO users (orderid, type, amount, status, created_at, time) "\
        "VALUES (:orderid, :type, :amount, :status, :created_at, :time)";
    query.prepare(sql_cmd_str);
    query.bindValue(":orderid", pay_order_id);
    query.bindValue(":type", type);
    query.bindValue(":amount", amount);
    query.bindValue(":status", status);
    query.bindValue(":created_at", localTimeStr);
    query.bindValue(":time", time);


    if (!query.exec()) {
        qCritical(IPAY) << "Insert fail";
    }
    return true;
}


bool DBOps::cleanOldData(QSqlQuery& query) {
    query.exec("DELETE FROM employees WHERE created_at < DATE('now', '-30 days')");

    // 检查删除了多少条记录
    int deletedCount = query.numRowsAffected();
    qInfo(IPAY) << "Has delete item: " << deletedCount;
    return true;
}


bool DBOps::queryPayOrderID(const QString& pay_order_id, QString& amount) {
    qInfo(IPAY) << "queryPayOrderID: " << pay_order_id;
    QSqlQuery query(m_db);
        query.prepare("SELECT amount FROM users WHERE orderid = :orderid");
    query.bindValue(":orderid", pay_order_id); // 替换为实际变量
    if (query.exec() && query.next()) {
        QString raw_amount = query.value(0).toString();
        amount = convertYuanToFen(raw_amount);
        qInfo(IPAY) << "订单存在，处理amount值(单位: 分): " << amount;

        return true;
    }
    amount = "0";
    return false;
}


QString DBOps::convertYuanToFen(const QString &yuanStr) {
    // 去除前导零和符号（如果有）
    QString normalized = yuanStr.trimmed();
    if (normalized.startsWith('+')) {
        normalized = normalized.mid(1);
    }

    // 正则表达式验证金额格式
    QRegularExpression re("^0*([1-9]\\d*|0)(\\.\\d{0,2})?$");
    QRegularExpressionMatch match = re.match(normalized);

    if (!match.hasMatch()) {
        return QString(); // 无效格式，返回空字符串
    }

    // 提取整数部分和小数部分
    QString intPart = match.captured(1);
    QString decimalPart = match.captured(2);

    // 处理小数部分（如果有）
    if (!decimalPart.isEmpty()) {
        decimalPart = decimalPart.mid(1); // 去掉小数点
        // 补零到两位
        while (decimalPart.length() < 2) {
            decimalPart.append('0');
        }
        // 截断超过两位的小数
        decimalPart = decimalPart.left(2);
    } else {
        // 没有小数部分，补两个零
        decimalPart = "00";
    }

    // 合并结果并移除前导零
    QString result = intPart + decimalPart;
    result = result.remove(0, result.indexOf(QRegularExpression("[1-9]")));

    // 处理全零的情况
    return result.isEmpty() ? "0" : result;
}

