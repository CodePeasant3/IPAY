#ifndef PAYMENTPLATFORM_H
#define PAYMENTPLATFORM_H

#include <QMainWindow>
#include <QPixmap>
#include <QAction>


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


private:
    Ui::PaymentPlatform *ui;
    QAction * receiptAction_ = nullptr;
    QAction * refundActuin_ = nullptr;
    QAction * detailAction_ = nullptr;
    QAction * settingAction_ = nullptr;
    QAction * exitAction_ = nullptr;
    QMenu * pushMenu_ = nullptr;
};
#endif // PAYMENTPLATFORM_H
