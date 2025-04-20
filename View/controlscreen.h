#ifndef CONTROLSCREEN_H
#define CONTROLSCREEN_H

#include <QWidget>
#include<QPainter>
#include<QImage>


namespace Ui {
class ControlScreen;
}

class ControlScreen : public QWidget
{
    Q_OBJECT

public:
    explicit ControlScreen(QWidget *parent = nullptr);
    ~ControlScreen();
    void ScreenInit();

public slots:
    void cancelBtn_slot();

    void finishBtn_slot();

signals:
    void cancel_save_screen();
    void finish_save_screen();


private:
    Ui::ControlScreen *ui;
};

#endif // CONTROLSCREEN_H
