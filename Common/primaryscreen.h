#ifndef PRIMARYSCREEN_H
#define PRIMARYSCREEN_H
#include <QGuiApplication>
#include <QScreen>
#include <atlbase.h>
#include <gdiplus.h>
#include <QImage>
#include <QString>
namespace ipay{
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

}

#endif // PRIMARYSCREEN_H
