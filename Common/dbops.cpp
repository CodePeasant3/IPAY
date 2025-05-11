#include "dbops.h"
#include <iostream>
#include <qlogging.h>
#include <QSqlQuery>
#include <QVariant>
#include <QTime>

int DBOps::init() {
    m_db = QSqlDatabase::addDatabase("QSQLITE", "iPayOrderList");
    m_db.setHostName("localhost");  //数据库主机名
    m_db.setDatabaseName("ipay.db");   //数据库名
    if(!m_db.open()) {
        std::cerr << "DB not opened" << std::endl;
        return -1;
    }
    std::cout << "db is open: " << m_db.isOpen() << std::endl;
    QSqlQuery query(m_db);
    this->createTable(query);
    this->cleanOldData(query);

    this->insertData(query, "00000", "202505110011", "200", 1);
    return 0;
}

void DBOps::final() {
    m_db.close();
    return;
}


int DBOps::createTable(QSqlQuery& query) {
    QString sql =
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "payOrderId TEXT UNIQUE, "
        "time TEXT NOT NULL, "
        "amount TEXT NOT NULL, "
        "status INTEGER, "
        "created_at DATETIME DEFAULT CURRENT_TIMESTAMP"
        ")";

    if (!query.exec(sql)) {
        std::cerr << "create table failed" << std::endl;
        return -1;
    }

    std::cout << "crate table success" << std::endl;
    return 0;
}

bool DBOps::insertData(QSqlQuery& query, QString pay_order_id, QString time, QString amount, int status) {
    QString sqlInsertWithoutTime =
        "INSERT OR IGNORE INTO users (payOrderId, time, amount, status, created_at) VALUES (:payOrderId, :time, :amount, :status, :created_at)";
    QString localTimeStr = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    query.prepare(sqlInsertWithoutTime);
    query.bindValue(":payOrderId", pay_order_id);
    query.bindValue(":time", time);
    query.bindValue(":amount", amount);
    query.bindValue(":status", status);
    query.bindValue(":created_at", localTimeStr);

    if (!query.exec()) {
        std::cerr << "Insert fail"  << std::endl;
    }
    return true;
}


bool DBOps::cleanOldData(QSqlQuery& query) {
    query.exec("DELETE FROM employees WHERE created_at < DATE('now', '-30 days')");

    // 检查删除了多少条记录
    int deletedCount = query.numRowsAffected();
    std::cerr << "Has delete item: " << deletedCount << std::endl;
    return true;
}

