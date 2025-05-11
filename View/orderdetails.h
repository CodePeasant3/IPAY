#ifndef ORDERDETAILS_H
#define ORDERDETAILS_H

#include "qstandarditemmodel.h"
#include <QWidget>
#include <QListWidgetItem>
#include "Common/dbops.h"
#include <QSqlTableModel>

namespace Ui {
class OrderDetails;
}

class OrderDetails : public QWidget
{
    Q_OBJECT

public:
    explicit OrderDetails(QWidget *parent = nullptr);
    ~OrderDetails();
    void  Init();

private:
    Ui::OrderDetails *ui;
    // QStandardItemModel *model = nullptr;
    std::shared_ptr<QSqlTableModel> model;
    QListWidgetItem *cashDetail_ = nullptr;
private:
    DBOps db_ops;
};

#endif // ORDERDETAILS_H
