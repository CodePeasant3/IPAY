#ifndef KEYBOARDRECORDOPERATION_H
#define KEYBOARDRECORDOPERATION_H

#include <QWidget>
#include "../Common/globalstatuscommon.h"
#include <Windows.h>
#include <QDebug>
#include "../Common/savesettingstruct.h"
#include <mutex>
#include <thread>

namespace Ui {
class KeyboardRecordOperation;
}

class KeyboardRecordOperation : public QWidget
{
    Q_OBJECT

public:
    explicit KeyboardRecordOperation(QWidget *parent = nullptr);
    ~KeyboardRecordOperation();
    static LRESULT CALLBACK KeyboardProcUtil(int nCode, WPARAM wParam, LPARAM lParam);
    static LRESULT CALLBACK MouseProcUtil(int nCode, WPARAM wParam, LPARAM lParam);
    void Init();
    void StartRecordKeyboard();
    void StopRecordKeyboard();
    void ModifyRecordInfo();

private slots:
    void on_pushButton_stop_record_clicked();


signals:
    void stop_keyboard_record();

private:
    Ui::KeyboardRecordOperation *ui;
    bool recordFlags_ = false;
    bool modify_record_flag_ = false;
protected:
    void closeEvent(QCloseEvent *event) override;
};

#endif // KEYBOARDRECORDOPERATION_H
