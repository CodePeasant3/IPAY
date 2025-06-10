#ifndef DBOPS_H
#define DBOPS_H
#include <QtSql/QSqlDatabase>
#include <QString>
#include <QRegularExpression>


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
    bool queryPayOrderID(const QString& pay_order_id, QString& amount);
    bool cleanOldData(QSqlQuery& query);

private:
    QString convertYuanToFen(const QString &yuanStr);
};

#endif // DBOPS_H
