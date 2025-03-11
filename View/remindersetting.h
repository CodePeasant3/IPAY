#ifndef REMINDERSETTING_H
#define REMINDERSETTING_H

#include <QWidget>

namespace Ui {
class ReminderSetting;
}

class ReminderSetting : public QWidget
{
    Q_OBJECT

public:
    explicit ReminderSetting(QWidget *parent = nullptr);
    ~ReminderSetting();

private:
    Ui::ReminderSetting *ui;
};

#endif // REMINDERSETTING_H
