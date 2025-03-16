#ifndef PRIMARYSCREEN_H
#define PRIMARYSCREEN_H
#include <QGuiApplication>
#include <QScreen>

class PrimaryScreen
{
public:
    PrimaryScreen();
    void GetInit();
    QRect GetGeometryScreen(){
        QScreen *primaryScreen = QGuiApplication::primaryScreen();
        return primaryScreen->geometry();
    };


};

#endif // PRIMARYSCREEN_H
