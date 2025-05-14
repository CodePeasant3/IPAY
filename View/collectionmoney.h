#ifndef COLLECTIONMONEY_H
#define COLLECTIONMONEY_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class CollectionMoney;
}

class CollectionMoney : public QWidget
{
    Q_OBJECT

public:
    explicit CollectionMoney(QWidget *parent = nullptr);
    ~CollectionMoney();
    void Init();
    void FuncationShow(std::string titleStr,std::string remindStr,std::string functionStr);
    void ReceiveMoney(); // 金额收款

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

public slots:
    void operationShow(int flags);
    void transferMoney(std::string money);

signals:
    void receiveFlags(QString qrStr);
    void showKeyboard();

private slots:
    void on_pushButton_qr_clicked();


private:
    Ui::CollectionMoney *ui;
    int funcationFlags_;
    std::string receiveMoney_;
};

#endif // COLLECTIONMONEY_H
