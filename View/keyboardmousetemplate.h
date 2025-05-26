#ifndef KEYBOARDMOUSETEMPLATE_H
#define KEYBOARDMOUSETEMPLATE_H

#include <QWidget>
#include "../Common/savesettingstruct.h"

namespace Ui {
class KeyboardMouseTemplate;
}

class KeyboardMouseTemplate : public QWidget
{
    Q_OBJECT

public:
    explicit KeyboardMouseTemplate(QWidget *parent = nullptr);
    ~KeyboardMouseTemplate();
    void Init(int index,std::string labelContext,ipay::ScenePlaybackType type);

signals:
    void clickClose(ipay::ScenePlaybackType type,int index);


private:
    Ui::KeyboardMouseTemplate *ui;
    int index_;
    ipay::ScenePlaybackType type_;
};

#endif // KEYBOARDMOUSETEMPLATE_H
