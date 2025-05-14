#include "playsetting.h"
#include "ui_playsetting.h"

PlaySetting::PlaySetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlaySetting)
{
    ui->setupUi(this);
    init();
}

PlaySetting::~PlaySetting()
{
    delete ui;
}

void PlaySetting::init()
{
    this->setWindowFlags(this->windowFlags() &~ Qt::WindowMinMaxButtonsHint);//禁止最大和最小化
    cashRegisterSetting_= new QListWidgetItem(QIcon(":/Resources/image/cashRegisterSetting.png"),"收银设置");
    reminderSetting_= new QListWidgetItem(QIcon(":/Resources/image/reminderSetting.png"),"提醒设置");
    scanCodeSetting_= new QListWidgetItem(QIcon(":/Resources/image/scanCodeSetting.png"),"扫码设置");
    commonSetting_= new QListWidgetItem(QIcon(":/Resources/image/commonSetting.png"),"常用功能");
    miscellaneousFunction_= new QListWidgetItem(QIcon(":/Resources/image/miscellaneousFunction.png"),"辅助功能");
    advancedFunction_= new QListWidgetItem(QIcon(":/Resources/image/advancedFunction.png"),"高级功能");

    ui ->listWidget_toolbar ->addItem(cashRegisterSetting_);
    ui ->listWidget_toolbar ->addItem(reminderSetting_);
    ui ->listWidget_toolbar ->addItem(scanCodeSetting_);
    ui ->listWidget_toolbar ->addItem(commonSetting_);
    ui ->listWidget_toolbar ->addItem(miscellaneousFunction_);
    ui ->listWidget_toolbar ->addItem(advancedFunction_);
    ui ->listWidget_toolbar ->setSpacing(20);

//    CustomDelegate* delegate = new CustomDelegate(ui->listWidget_toolbar);
//    ui->listWidget_toolbar->setItemDelegate(delegate);

    ui ->widget_cashRegisterSetting ->show();
    ui ->widget_reminderSetting->hide();
    ui ->widget_scanCodeSetting ->hide();
    ui ->widget_commonSetting ->hide();
    ui ->widget_miscellaneousFunction ->hide();
    ui ->widget_advancedFunction ->hide();

    mapWidgetItem_.insert(0,ui ->widget_cashRegisterSetting);
    mapWidgetItem_.insert(1,ui ->widget_reminderSetting);
    mapWidgetItem_.insert(2,ui ->widget_scanCodeSetting);
    mapWidgetItem_.insert(3,ui ->widget_commonSetting);
    mapWidgetItem_.insert(4,ui ->widget_miscellaneousFunction);
    mapWidgetItem_.insert(5,ui ->widget_advancedFunction);

    ui->listWidget_toolbar->setStyleSheet("QListWidget::item { color: #bfbfbf; }");
    connect(ui ->listWidget_toolbar, &QListWidget::itemSelectionChanged, this, &PlaySetting::OnItemSelectionChanged);

    connect(ui ->widget_cashRegisterSetting,&CashRegisterSetting::start_keyboard_record,this,&PlaySetting::start_keyboard_record);

    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
    this->setWindowTitle("设置");
}

void PlaySetting::OnItemSelectionChanged()
{
    QListWidgetItem *selectedItem = ui ->listWidget_toolbar ->currentItem();
    if (!selectedItem)
        return;

    int rowIndex = ui ->listWidget_toolbar ->row(selectedItem);
    QMapIterator<int, QWidget*> it(mapWidgetItem_);
    while (it.hasNext()) {
        it.next();
        if(it.key() == rowIndex){
            it.value()->show();
            continue;
        }
        it.value()->hide();
    }


}

void PlaySetting::closeEvent(QCloseEvent *event) {
    // TODO(Shucong): 去触发paymentPlatform的setEnable(true);
    event->accept();
}

