#ifndef ADVANCEDFUNCTION_H
#define ADVANCEDFUNCTION_H

#include <QWidget>

namespace Ui {
class AdvancedFunction;
}

class AdvancedFunction : public QWidget
{
    Q_OBJECT

public:
    explicit AdvancedFunction(QWidget *parent = nullptr);
    ~AdvancedFunction();

private:
    Ui::AdvancedFunction *ui;
};

#endif // ADVANCEDFUNCTION_H
