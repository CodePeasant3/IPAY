#ifndef PAYMENTPLATFORM_H
#define PAYMENTPLATFORM_H

#include <QMainWindow>
#include <QPixmap>
#include <QAction>
#include <string>
#include "../Common/globalstatuscommon.h"


QT_BEGIN_NAMESPACE
namespace Ui { class PaymentPlatform; }
QT_END_NAMESPACE

class PaymentPlatform : public QMainWindow
{
    Q_OBJECT

public:
    PaymentPlatform(QWidget *parent = nullptr);
    ~PaymentPlatform();
    void init();
    void exit();
signals:
    void ShowCashKeyboard();
    void ShowCashKeyboardModify();
    void ShowCollecton();
    void ShowSetting();
    void ClickExit();
    void ShowDetails();
    void StartModel(int flags);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

 public slots:
    void ReceiveMoney(std::string moneyNumber);
    void EnableOperation();




private:
    Ui::PaymentPlatform *ui;
    QAction * receiptAction_ = nullptr;
    QAction * refundActuin_ = nullptr;
    QAction * modifyMoney_ = nullptr;
    QAction * detailAction_ = nullptr;
    QAction * settingAction_ = nullptr;
    QAction * exitAction_ = nullptr;
    QMenu * pushMenu_ = nullptr;
    QPoint offset;
    bool mousePressed;
};
#endif // PAYMENTPLATFORM_H
