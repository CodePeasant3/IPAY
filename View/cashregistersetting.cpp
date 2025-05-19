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
    if(!cash_register_setting_struct_.screen_pixmap.isNull()){
        QPixmap scaledPixmap = cash_register_setting_struct_.screen_pixmap.scaled(cash_register_setting_struct_.screen_pixmap_w, cash_register_setting_struct_.screen_pixmap_h, Qt::KeepAspectRatio);
        ui->recognition_label->setPixmap(scaledPixmap);
    }

}

void CashRegisterSetting::CreateWidgetItem()
{
    QListWidgetItem *KM_EVENT = new QListWidgetItem(ui->listWidget_keyboard);



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
























