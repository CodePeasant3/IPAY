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
    this->setWindowFlags(windowFlags() &~ Qt::WindowMinMaxButtonsHint);//禁止最大和最小化
    this->setFixedSize(800,550);
    this->setWindowTitle("OrderList");

    cashDetail_= new QListWidgetItem(QIcon(":/Resources/image/CashDetail.png"),"明细");
    ui ->listWidget_toolbar ->addItem(cashDetail_);
    CustomDelegate* delegate = new CustomDelegate(ui->listWidget_toolbar);
    ui->listWidget_toolbar->setItemDelegate(delegate);
    ui->listWidget_toolbar->setStyleSheet("QListWidget::item { color: #bfbfbf; }");

    int ret = db_ops.init();
    if(ret) {
        qWarning() << "DB ops init failed";
    }
    model = std::make_shared<QSqlTableModel>(this, db_ops.m_db);
    model->setTable("users");
    model->select();

    model->setHeaderData(1, Qt::Horizontal, "订单号");
    model->setHeaderData(2, Qt::Horizontal, "交易时间");
    model->setHeaderData(3, Qt::Horizontal, "金额");
    model->setHeaderData(4, Qt::Horizontal, "状态");

    ui ->tableView_order->setModel(model.get());
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

    // 备用
    // 刷新数据
    // model->select();
    // tableView->resizeColumnsToContents();
}
