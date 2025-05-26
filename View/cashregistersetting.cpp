#include "cashregistersetting.h"
#include "ui_cashregistersetting.h"

CashRegisterSetting::CashRegisterSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CashRegisterSetting)
{
    ui->setupUi(this);
    Init();
}

CashRegisterSetting::~CashRegisterSetting()
{
    delete ui;
}

void CashRegisterSetting::Init()
{

//ui ->pushButton_save ->setStyleSheet("QPushButton {border-radius: 3%;}");
    UIStatus();
    QIntValidator *intValidator = new QIntValidator(this);
    ui->lineEdit->setValidator(intValidator);
    connect(ui->radioButton_cycle,&QRadioButton::clicked,this,&CashRegisterSetting::RegisterArea);
    connect(ui->radioButton_once,&QRadioButton::clicked,this,&CashRegisterSetting::RegisterArea);
    connect(ui->radioButton_money_back,&QRadioButton::clicked,this,&CashRegisterSetting::RegisterArea);


    ui->listWidget_keyboard->setViewMode(QListView::IconMode);
    ui->listWidget_keyboard->setFlow(QListView::LeftToRight);  // 从左到右排列
    ui->listWidget_keyboard->setWrapping(true);                // 自动换行
    ui->listWidget_keyboard->setResizeMode(QListView::Adjust); // 调整大小时重新排列

    // 设置项之间的间距
    ui->listWidget_keyboard->setSpacing(10);

    connect(ui->tabWidget,&QTabWidget::currentChanged,[=](int index){
        if(index == 1){
            init_show();
        }
    });


}

void CashRegisterSetting::UIStatus()
{
    cash_register_setting_struct_ = ipay::GlobalStatusCommon::instance()->GetAllSettingConfig()->cash_register_setting;
    ui->radioButton_cycle->setChecked(cash_register_setting_struct_.recognition_type == 0);
    ui->radioButton_once->setChecked(cash_register_setting_struct_.recognition_type == 1);
    ui->radioButton_money_back->setChecked(cash_register_setting_struct_.enable_money_playback == 1);
    cash_register_setting_struct_.automatic_amount_entry == 0 ?
                ui ->pushButton_auto_clean->setText("手动"):ui ->pushButton_auto_clean->setText("自动");
    ui->lineEdit->setText(QString::number(cash_register_setting_struct_.interaval_entry_ms));
    if(cash_register_setting_struct_.screen_pixmap.isNull()){
        ui->recognition_label->clear();
        return;
    }
    QPixmap scaledPixmap = cash_register_setting_struct_.screen_pixmap.scaled(cash_register_setting_struct_.screen_pixmap_w, cash_register_setting_struct_.screen_pixmap_h, Qt::KeepAspectRatio);
    ui->recognition_label->setPixmap(scaledPixmap);

}

void CashRegisterSetting::CreateWidgetItem()
{
    QListWidgetItem *KM_EVENT = new QListWidgetItem(ui->listWidget_keyboard);



}

QListWidgetItem *CashRegisterSetting::GetQListWidget(ipay::ScenePlaybackType type, int index)
{
    if(type == ipay::ScenePlaybackType::CALLBACKCLEANTABLE){
        return ui->listWidget_keyboard->takeItem(index);
    }
}

QWidget *CashRegisterSetting::GetQListItemWidget(ipay::ScenePlaybackType type, QListWidgetItem* item)
{
    if(type == ipay::ScenePlaybackType::CALLBACKCLEANTABLE){
        return ui->listWidget_keyboard->itemWidget(item);
    }

}

int CashRegisterSetting::GetQListItemSize(ipay::ScenePlaybackType type)
{
    if(type == ipay::ScenePlaybackType::CALLBACKCLEANTABLE){
        return ui->listWidget_keyboard->count();
    }
    return 0;
}


void CashRegisterSetting::delete_record_keyboard_by_type( const std::vector<ipay::KeyboardMouseRecordStruct> &recordVector,
                                                         ipay::ScenePlaybackType type)
{
    int total_size = GetQListItemSize(type);
    for (int i = 0; i < total_size; ++i) {
        QListWidgetItem* item = GetQListWidget(type,i);
        if (item) {
            QWidget* widget = GetQListItemWidget(type,item);
            if (widget) {
                delete widget;
            }
            delete item;
        }
    }
}


// 设置识别区域
void CashRegisterSetting::on_pushButton_recognition_clicked()
{
    if(!scr_){
        scr_ = new Screen();
        QWidget* control = new QWidget(scr_);
        ControlScreen* controlUi = new ControlScreen(control);
        controlUi->ScreenInit();
        scr_ ->setControlScreen(controlUi,control);
        connect(controlUi,&ControlScreen::cancel_save_screen,this, &CashRegisterSetting::close_screen);
        connect(controlUi,&ControlScreen::finish_save_screen,this, &CashRegisterSetting::save_picture);
        scr_->show();
    }


}


void CashRegisterSetting::on_pushButton_save_clicked()
{
    cash_register_setting_struct_.interaval_entry_ms = ui->lineEdit->text().toInt();
    ipay::GlobalStatusCommon::instance()->ModifyCashRegisterSetting(cash_register_setting_struct_);
    emit hideSettingPage();
}


void CashRegisterSetting::on_pushButton_cancel_clicked()
{
    UIStatus();
    emit hideSettingPage();
}

void CashRegisterSetting::RegisterArea()
{
    if(ui->radioButton_cycle->isChecked()){
        cash_register_setting_struct_.recognition_type = 0;
    }else if(ui->radioButton_once ->isChecked()){
        cash_register_setting_struct_.recognition_type = 1;
    }else if(ui->radioButton_money_back->isChecked()){
        cash_register_setting_struct_.enable_money_playback = !cash_register_setting_struct_.enable_money_playback;
    }
}

//开始录制
void CashRegisterSetting::on_pushButton_record_clicked()
{
    ipay::GlobalStatusCommon::instance()->StartRecordKeyboard(ipay::ScenePlaybackType::CALLBACKCLEANTABLE);
    emit start_keyboard_record();

}

//自动录入软件
void CashRegisterSetting::on_pushButton_auto_clean_clicked()
{
    cash_register_setting_struct_.automatic_amount_entry = !cash_register_setting_struct_.automatic_amount_entry;
    cash_register_setting_struct_.automatic_amount_entry == 0 ?
                ui ->pushButton_auto_clean->setText("手动"):ui ->pushButton_auto_clean->setText("自动");
}


void CashRegisterSetting::on_radioButton_money_back_clicked()
{
    cash_register_setting_struct_.enable_money_playback = !cash_register_setting_struct_.enable_money_playback;
}

void CashRegisterSetting::close_screen()
{
    if(scr_){
        scr_->hide();
        delete scr_;
        scr_ = nullptr;
    }

}

void CashRegisterSetting::save_picture()
{
    QPixmap screen_save =  scr_->GetGrabPixmap();
    std::vector<int> coordinate = scr_->GetPictureCoordinate();
    cash_register_setting_struct_.screen_x = coordinate.at(0);
    cash_register_setting_struct_.screen_y = coordinate.at(1);
    cash_register_setting_struct_.screen_w = coordinate.at(2);
    cash_register_setting_struct_.screen_h = coordinate.at(3);
    cash_register_setting_struct_.screen_pixmap = screen_save;
    if (!screen_save.isNull()) {
        QPixmap scaledPixmap = screen_save.scaled(ui->recognition_label->width(), ui->recognition_label->height(), Qt::KeepAspectRatio);
        ui->recognition_label->setPixmap(scaledPixmap);
        cash_register_setting_struct_.screen_pixmap_w = ui->recognition_label->width();
        cash_register_setting_struct_.screen_pixmap_h = ui->recognition_label->height();
    }
}

void CashRegisterSetting::save_keyboard_operation()
{
    std::vector<ipay::KeyboardMouseRecordStruct>& recordVector = ipay::GlobalStatusCommon::instance()
            ->GetKeyboardMouseList(ipay::ScenePlaybackType::CALLBACKCLEANTABLE);
    if(recordVector.empty()){
        return;
    }
    delete_record_keyboard_by_type(recordVector,ipay::ScenePlaybackType::CALLBACKCLEANTABLE);
    int itemWidth = (ui->listWidget_keyboard->width() - 30) / 4;
    int itemHeight = (ui->listWidget_keyboard->height() - 30) / 4;
    if(keyboard_ui_w == -1){
        keyboard_ui_w = itemWidth;
        keyboard_ui_h = itemHeight;
    }
    for (int i = 0; i < recordVector.size(); i++) {
        ipay::KeyboardMouseRecordStruct recordStruct = recordVector.at(i);
        QListWidgetItem *item = new QListWidgetItem(ui->listWidget_keyboard);
        KeyboardMouseTemplate *template_keyboard = new KeyboardMouseTemplate(this);
        template_keyboard->Init(recordStruct.record_index, recordStruct.value,ipay::ScenePlaybackType::CALLBACKCLEANTABLE);
        item->setSizeHint(QSize(itemWidth, itemHeight));
        ui->listWidget_keyboard->setItemWidget(item, template_keyboard);
        connect(template_keyboard,&KeyboardMouseTemplate::clickClose,this,&CashRegisterSetting::delete_record_keyboard);
    }
}

void CashRegisterSetting::delete_record_keyboard(ipay::ScenePlaybackType type, int index)
{
    auto& recordVector  = ipay::GlobalStatusCommon::instance()
            ->GetKeyboardMouseList(type);

    for (int i = 0; i < recordVector.size(); ++i) {
        if(recordVector.at(i).record_index == index){
            QListWidgetItem* item = GetQListWidget(type,i);
            if (item) {
                QWidget* widget = GetQListItemWidget(type,item);
                if (widget) {
                    delete widget;
                }
                delete item;
            }
            recordVector.erase(recordVector.begin() + i);
            return;
        }
    }

}

void CashRegisterSetting::init_show()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::vector<ipay::KeyboardMouseRecordStruct>& recordVector = ipay::GlobalStatusCommon::instance()
            ->GetFinshKeyboardMouseList(ipay::ScenePlaybackType::CALLBACKCLEANTABLE);
    save_keyboard_operation();

}
























