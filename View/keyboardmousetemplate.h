#ifndef KEYBOARDMOUSETEMPLATE_H
#define KEYBOARDMOUSETEMPLATE_H

#include <QWidget>

namespace Ui {
class KeyboardMouseTemplate;
}

class KeyboardMouseTemplate : public QWidget
{
    Q_OBJECT

public:
    explicit KeyboardMouseTemplate(QWidget *parent = nullptr);
    ~KeyboardMouseTemplate();
    void Init(int index,std::string & labelContext);

signals:
    void clickClose(int index);


private:
    Ui::KeyboardMouseTemplate *ui;
    int index_;
};

#endif // KEYBOARDMOUSETEMPLATE_H
