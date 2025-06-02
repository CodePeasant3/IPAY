#ifndef DBOPS_H
#define DBOPS_H
#include <QtSql/QSqlDatabase>
class DBOps
{
public:
    int init();
    void final();
    QSqlDatabase m_db;

public:
    int createTable(QSqlQuery& query);
    bool insertData(QString pay_order_id,
                    int type,
                    QString time,
                    QString amount,
                    int status);
    bool cleanOldData(QSqlQuery& query);
};

#endif // DBOPS_H
