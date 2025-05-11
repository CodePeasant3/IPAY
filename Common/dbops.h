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
    int createTable();
    bool insertData(QString pay_order_id,QString time,QString amount,int status);

    void insertTestData();

};

#endif // DBOPS_H
