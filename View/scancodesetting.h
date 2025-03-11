#ifndef SCANCODESETTING_H
#define SCANCODESETTING_H

#include <QWidget>

namespace Ui {
class ScanCodeSetting;
}

class ScanCodeSetting : public QWidget
{
    Q_OBJECT

public:
    explicit ScanCodeSetting(QWidget *parent = nullptr);
    ~ScanCodeSetting();

private:
    Ui::ScanCodeSetting *ui;
};

#endif // SCANCODESETTING_H
