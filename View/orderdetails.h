#ifndef ORDERDETAILS_H
#define ORDERDETAILS_H

#include "qstandarditemmodel.h"
#include <QWidget>
#include <QListWidgetItem>
#include "Common/dbops.h"
#include <QSqlTableModel>
#include "Common/dbops.h"
#include <QIdentityProxyModel>



namespace Ui {
class OrderDetails;
}

class CustomProxyModel : public QIdentityProxyModel {
    Q_OBJECT
public:
    explicit CustomProxyModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

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
    std::shared_ptr<CustomProxyModel> proxy;
    QListWidgetItem *cashDetail_ = nullptr;
protected:
    void closeEvent(QCloseEvent *event) override;

};

#endif // ORDERDETAILS_H
