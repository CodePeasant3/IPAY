#ifndef CASHREGISTERKEYBOARD_H
#define CASHREGISTERKEYBOARD_H

#include <QWidget>
#include <string>
#include <vector>

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

signals:
    void CollectMoney(std::string money);
    void FinalMoney(std::string money);

public slots:
    void KeyboardShow();
    void ModifyMoney(std::string number);
    void DeleteMoney();
    void ChangeMonet();

private:
    Ui::CashRegisterKeyboard *ui;
    bool isShow_ = false;
    static std::vector<std::string> money_vector_;
};

#endif // CASHREGISTERKEYBOARD_H
