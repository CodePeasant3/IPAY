#include "dbops.h"
#include <iostream>
#include <qlogging.h>
#include <QSqlQuery>
#include <QVariant>

int DBOps::init() {
    m_db = QSqlDatabase::addDatabase("QSQLITE", "iPayOrderList");
    m_db.setHostName("localhost");  //数据库主机名
    m_db.setDatabaseName("ipay.db");   //数据库名
    if(!m_db.open()) {
        std::cerr << "DB not opened" << std::endl;
        return -1;
    }
    std::cout << "db is open: " << m_db.isOpen() << std::endl;
    this->createTable();
    this->insertData("111", "202505110011", "100", 1);
    return 0;
}

void DBOps::final() {
    m_db.close();
    return;
}


int DBOps::createTable() {
    QSqlQuery query(m_db);

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

bool DBOps::insertData(QString pay_order_id, QString time, QString amount, int status) {
    QSqlQuery query(m_db);

    QString sqlInsertWithoutTime =
        "INSERT OR IGNORE INTO users (payOrderId, time, amount, status) VALUES (:payOrderId, :time, :amount, :status)";


    query.prepare(sqlInsertWithoutTime);
    query.bindValue(":payOrderId", pay_order_id);
    query.bindValue(":time", time);
    query.bindValue(":amount", amount);
    query.bindValue(":status", status);

    if (!query.exec()) {
        std::cerr << "Insert fail"  << std::endl;
    }
    return true;
}

void DBOps::insertTestData() {

}

