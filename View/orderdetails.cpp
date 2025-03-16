#include "orderdetails.h"
#include "playsetting.h"
#include "ui_orderdetails.h"

OrderDetails::OrderDetails(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderDetails)
{
    ui->setupUi(this);
    Init();
}

OrderDetails::~OrderDetails()
{
    delete ui;
}

void OrderDetails::Init()
{

    cashDetail_= new QListWidgetItem(QIcon(":/Resources/image/CashDetail.png"),"明细");
    ui ->listWidget_toolbar ->addItem(cashDetail_);
    CustomDelegate* delegate = new CustomDelegate(ui->listWidget_toolbar);
    ui->listWidget_toolbar->setItemDelegate(delegate);
    ui->listWidget_toolbar->setStyleSheet("QListWidget::item { color: #bfbfbf; }");

    model = new QStandardItemModel();
    model->setColumnCount(5);
    model->setHeaderData(0,Qt::Horizontal, "支付方式");
    model->setHeaderData(1,Qt::Horizontal, "订单号");
    model->setHeaderData(2,Qt::Horizontal, "交易时间");
    model->setHeaderData(3,Qt::Horizontal, "金额");
    model->setHeaderData(4,Qt::Horizontal, "状态");
    ui ->tableView_order->setModel(model);
    QString styleSheet = "QHeaderView::section {"
                           "background-color: #cdcdcd;"
                           "color: #8a8a8a;"
                           "border: 1px solid #e6e6e6;"
                           "}";
      ui->tableView_order->horizontalHeader()->setStyleSheet(styleSheet);
}
