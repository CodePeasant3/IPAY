#ifndef COMMONSETTING_H
#define COMMONSETTING_H

#include <QWidget>

namespace Ui {
class CommonSetting;
}

class CommonSetting : public QWidget
{
    Q_OBJECT

public:
    explicit CommonSetting(QWidget *parent = nullptr);
    ~CommonSetting();

private:
    Ui::CommonSetting *ui;
};

#endif // COMMONSETTING_H
