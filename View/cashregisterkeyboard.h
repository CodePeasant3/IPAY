#ifndef CASHREGISTERKEYBOARD_H
#define CASHREGISTERKEYBOARD_H

#include <QWidget>
#include <string>
#include <vector>
#include <QMessageBox>
#include "../Common/globalstatuscommon.h"

namespace Ui {
class CashRegisterKeyboard;
}

class CashRegisterKeyboard : public QWidget
{
    Q_OBJECT

public:
    explicit CashRegisterKeyboard(QWidget *parent = nullptr);
    ~CashRegisterKeyboard();
    void Init();
    int MoneyBack(QString qrStr); //金额退款
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

private:
    Ui::CashRegisterKeyboard *ui;
    QTimer *process_timer_{nullptr};
    std::string money_result_;
    bool isShow_ = false;
    bool isDecimalPoint_ = false;
    static std::vector<std::string> money_vector_;
    QString qrStr_;
    int flags_;

};

#endif // CASHREGISTERKEYBOARD_H
