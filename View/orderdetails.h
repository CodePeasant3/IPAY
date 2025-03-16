#ifndef ORDERDETAILS_H
#define ORDERDETAILS_H

#include "qstandarditemmodel.h"
#include <QWidget>
#include <QListWidgetItem>

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
    QStandardItemModel *model = nullptr;
    QListWidgetItem *cashDetail_ = nullptr;
};

#endif // ORDERDETAILS_H
