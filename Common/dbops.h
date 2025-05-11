#ifndef DBOPS_H
#define DBOPS_H
#include <QtSql/QSqlDatabase>
class DBOps
{
public:
    int init();
    void final();
    QSqlDatabase m_db;
private:
    int createTable(QSqlQuery& query);
    bool insertData(QSqlQuery& query, QString pay_order_id,QString time,QString amount,int status);
    bool cleanOldData(QSqlQuery& query);
};

#endif // DBOPS_H
