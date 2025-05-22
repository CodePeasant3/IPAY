#include "keyboardrecordoperation.h"
#include "ui_keyboardrecordoperation.h"
#include <QCloseEvent>
#include <Common/logging.h>

std::vector<ipay::KeyboardMouseRecordStruct> keyboard_vector_;
HHOOK h_mouse_hook = NULL;
HHOOK h_keyboard_hook = NULL;
std::mutex keyboard_mtx_;
std::string record_info_str_;
bool over_modify_thread_ = false;


KeyboardRecordOperation::KeyboardRecordOperation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KeyboardRecordOperation)
{
    ui->setupUi(this);
    Init();
}

KeyboardRecordOperation::~KeyboardRecordOperation()
{
    over_modify_thread_ = true;
    delete ui;
}

LRESULT CALLBACK KeyboardRecordOperation::MouseProcUtil(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        POINT cursorPos;
        GetCursorPos(&cursorPos);
        ipay::KeyboardMouseRecordStruct km_record;
        km_record.mouse_x = cursorPos.x;
        km_record.mouse_y = cursorPos.y;
        switch (wParam) {
        case WM_LBUTTONDOWN:
            km_record.type = ipay::KeyboardMouseType::LIFTMOUSE;
            keyboard_vector_.emplace_back(km_record);
            record_info_str_ += "L( x:" + std::to_string(km_record.mouse_x)  + ", y:" + std::to_string(km_record.mouse_y) + " )";
            qDebug(IPAY) << "Left mouse button down X: " << cursorPos.x << " Y: " << cursorPos.y;
            break;
        case WM_LBUTTONUP:
            qDebug(IPAY) << "Left mouse button up";
            break;
        case WM_RBUTTONDOWN:
            km_record.type = ipay::KeyboardMouseType::RIGHTMOUSE;
            keyboard_vector_.emplace_back(km_record);
            record_info_str_ += "R( x:" + std::to_string(km_record.mouse_x)  + ", y:" + std::to_string(km_record.mouse_y) + " )";
            qDebug(IPAY) << "Right mouse button down";
            break;
        case WM_RBUTTONUP:
            qDebug(IPAY) << "Right mouse button up";
            break;
        }
    }
    return CallNextHookEx(h_mouse_hook, nCode, wParam, lParam);
}

void KeyboardRecordOperation::Init()
{
    auto modify_record_fun = std::bind(&KeyboardRecordOperation::ModifyRecordInfo,this);
    std::thread record_keyboard_thread(modify_record_fun);
    // win 7 核心库无法使用这个函数
//    SetThreadDescription(record_keyboard_thread.native_handle(), LPCWSTR("keyborad_record_thr_"));
    record_keyboard_thread.detach();
    this->setWindowFlags(this->windowFlags() &~ Qt::WindowMinMaxButtonsHint);//禁止最大和最小化
}


LRESULT CALLBACK KeyboardRecordOperation::KeyboardProcUtil(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        KBDLLHOOKSTRUCT* pKeyboardHook = (KBDLLHOOKSTRUCT*)lParam;
        ipay::KeyboardMouseRecordStruct km_record;
        km_record.type = ipay::KeyboardMouseType::KETBOARD;
        switch (wParam) {
        case WM_KEYDOWN:
            km_record.key_num = pKeyboardHook->vkCode;
            keyboard_vector_.emplace_back(km_record);
            record_info_str_ += "K (" + std::to_string(km_record.key_num) + " )";
            qDebug(IPAY) << "Key down:" << pKeyboardHook->vkCode;
            break;
        case WM_KEYUP:
            qDebug(IPAY) << "Key up:" << pKeyboardHook->vkCode;
            break;
        }
    }
    return CallNextHookEx(h_keyboard_hook, nCode, wParam, lParam);
};

void KeyboardRecordOperation::StartRecordKeyboard()
{
    std::lock_guard<std::mutex> lock(keyboard_mtx_);
    if(recordFlags_){
        QMessageBox::warning(this,"警告","请开始录制后重试！");
        return;
    }
    record_info_str_ = "";
    recordFlags_ = true;
    modify_record_flag_ = true;
    h_mouse_hook = SetWindowsHookEx(WH_MOUSE_LL, MouseProcUtil, NULL, 0);
    h_keyboard_hook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProcUtil, NULL, 0);
}

void KeyboardRecordOperation::StopRecordKeyboard()
{
    if (h_mouse_hook) {
        UnhookWindowsHookEx(h_mouse_hook);
        h_mouse_hook = NULL;
    }
    if (h_keyboard_hook) {
        UnhookWindowsHookEx(h_keyboard_hook);
        h_keyboard_hook = NULL;
    }
}

void KeyboardRecordOperation::ModifyRecordInfo()
{
    ui ->label_keyboard_info ->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    while (!over_modify_thread_) {
        if(!modify_record_flag_){
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }
        if(keyboard_vector_.size() == 0){
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }
        ui ->label_keyboard_info -> setText(QString::fromStdString(record_info_str_));
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void KeyboardRecordOperation::on_pushButton_stop_record_clicked()
{
    std::lock_guard<std::mutex> lock(keyboard_mtx_);
    if(!recordFlags_){
        QMessageBox::warning(this,"警告","请开始录制后重试！");
        return;
    }

    recordFlags_ = false;
    modify_record_flag_ = false;
    StopRecordKeyboard();
    // 去除点击 stop按钮
    keyboard_vector_.pop_back();
    ipay::GlobalStatusCommon::instance()->StopRecordKeyboard(keyboard_vector_);
    keyboard_vector_.clear();

    record_info_str_ = "";

    emit stop_keyboard_record();
}
void KeyboardRecordOperation::closeEvent(QCloseEvent *event) {
    event->accept();
    emit AllowOperation();
}









