#ifndef MISCELLANEOUSFUNCTION_H
#define MISCELLANEOUSFUNCTION_H

#include <QWidget>

namespace Ui {
class MiscellaneousFunction;
}

class MiscellaneousFunction : public QWidget
{
    Q_OBJECT

public:
    explicit MiscellaneousFunction(QWidget *parent = nullptr);
    ~MiscellaneousFunction();

private:
    Ui::MiscellaneousFunction *ui;
};

#endif // MISCELLANEOUSFUNCTION_H
