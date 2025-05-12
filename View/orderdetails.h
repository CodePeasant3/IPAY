#ifndef ORDERDETAILS_H
#define ORDERDETAILS_H

#include "qstandarditemmodel.h"
#include <QWidget>
#include <QListWidgetItem>
#include "Common/dbops.h"
#include <QSqlTableModel>
#include "Common/dbops.h"


namespace Ui {
class OrderDetails;
}

class OrderDetails : public QWidget
{
    Q_OBJECT

public:
    OrderDetails(DBOps& db_ops, QWidget *parent = nullptr);
    ~OrderDetails();
    void  Init(DBOps& db_ops);

private:
    Ui::OrderDetails *ui;
    // QStandardItemModel *model = nullptr;
    std::shared_ptr<QSqlTableModel> model;
    QListWidgetItem *cashDetail_ = nullptr;

};

#endif // ORDERDETAILS_H
