#include "orderdetails.h"
#include "playsetting.h"
#include "ui_orderdetails.h"


#include <QSqlTableModel>
#include <QString>
#include <QVariant>
#include <Qt>


CustomProxyModel::CustomProxyModel(QObject *parent) : QIdentityProxyModel(parent) {

}

QVariant CustomProxyModel::data(const QModelIndex &index, int role) const{
    if (role == Qt::DisplayRole && index.column() == 2) { // 第3列
        int status = sourceModel()->data(index, Qt::EditRole).toInt();
        switch (status) {
        case 1: return "付款";
        case 2: return "退款";
        }
    }
    if (role == Qt::DisplayRole && index.column() == 4) { // 第5列
        int status = sourceModel()->data(index, Qt::EditRole).toInt();
        switch (status) {
        case 1: return "完成";
        case 2: return "取消";
        }
    }
    return QIdentityProxyModel::data(index, role);
}

OrderDetails::OrderDetails(DBOps& db_ops, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderDetails)
{
    ui->setupUi(this);
    Init(db_ops);
}

OrderDetails::~OrderDetails()
{
    delete ui;
}

void OrderDetails::Init(DBOps& db_ops)
{
    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);

    cashDetail_= new QListWidgetItem(QIcon(":/Resources/image/CashDetail.png"),"明细");
    ui ->listWidget_toolbar ->addItem(cashDetail_);
    CustomDelegate* delegate = new CustomDelegate(ui->listWidget_toolbar);
    ui->listWidget_toolbar->setItemDelegate(delegate);
    ui->listWidget_toolbar->setStyleSheet("QListWidget::item { color: #bfbfbf; }");


    model = std::make_shared<QSqlTableModel>(this,db_ops.m_db);
    proxy =  std::make_shared<CustomProxyModel>();
    proxy->setSourceModel(model.get());

    model->setTable("users");
    model->select();

    model->setHeaderData(1, Qt::Horizontal, "订单号");
    model->setHeaderData(2, Qt::Horizontal, "交易类型");
    model->setHeaderData(3, Qt::Horizontal, "金额");
    model->setHeaderData(4, Qt::Horizontal, "交易状态");
    model->setHeaderData(5, Qt::Horizontal, "时间");


    ui ->tableView_order->setModel(proxy.get());
    ui ->tableView_order->resizeColumnsToContents();
    ui ->tableView_order->setAlternatingRowColors(true);

    QString styleSheet = "QHeaderView::section {"
                           "background-color: #cdcdcd;"
                           "color: #8a8a8a;"
                           "border: 1px solid #e6e6e6;"
                           "}";
    ui->tableView_order->horizontalHeader()->setStyleSheet(styleSheet);
    // 选中即选中整行
    ui->tableView_order->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 禁止修改
    ui->tableView_order->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // Header自动铺满窗体
    ui->tableView_order->horizontalHeader()->setStretchLastSection(true);
    ui->tableView_order->setColumnHidden(0, true);
    ui->tableView_order->setColumnHidden(6, true);



    // 备用
    // 刷新数据
    // model->select();
    // tableView->resizeColumnsToContents();
}
