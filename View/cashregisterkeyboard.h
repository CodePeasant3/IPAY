#ifndef CASHREGISTERKEYBOARD_H
#define CASHREGISTERKEYBOARD_H

#include <QWidget>
#include <string>
#include <vector>
#include <QMessageBox>
#include "../Common/globalstatuscommon.h"
#include <future>
#include <thread>
class DBOps;
class HttpsRequest;

namespace Ui {
class CashRegisterKeyboard;
}

class CashRegisterKeyboard : public QWidget
{
    Q_OBJECT

public:
    explicit CashRegisterKeyboard(QWidget *parent = nullptr);
    ~CashRegisterKeyboard();
    void Init(const ipay::KeyboardOperationType type, DBOps*, HttpsRequest*);
    int MoneyBack(); //金额退款
    bool isValidNumber(const QString &str);
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

signals:
    void CollectMoney(std::string money);
    void FinalMoney(std::string money);
    void ShowCollection();
    void SendMoneyNum(std::string money);
    void AllowOperation();

public slots:
    void KeyboardShow();
    void ModifyMoney(std::string number);
    void DeleteMoney();
    void ChangeMonet();
    void ReceiveQRInfo(QString qrStr);
    void operationShow(int flags);
    void ClickReceive();
    void killAlgoThread();
    void saveLastQR(const ipay::QRDetailStruct& qr_struct);
    void modifyMoneySlot();

private:
    Ui::CashRegisterKeyboard *ui;
    QTimer *process_timer_{nullptr};
    std::string money_result_;
    bool isShow_ = false;
    bool isDecimalPoint_ = false;
    std::vector<std::string> money_vector_;
    QString qrStr_;
    int flags_;
    int point_bit = 0;
    std::future<void> future_thread;
    ipay::QRDetailStruct lastQRDetail_;
    ipay::KeyboardOperationType self_type_;
    DBOps* m_db_ops;
    HttpsRequest* m_request;

};

#endif // CASHREGISTERKEYBOARD_H
