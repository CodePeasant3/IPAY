#include "controlscreen.h"
#include "ui_controlscreen.h"
#include <QDebug>
ControlScreen::ControlScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlScreen)
{
    ui->setupUi(this);
}

ControlScreen::~ControlScreen()
{
    delete ui;
}

void ControlScreen::ScreenInit()
{
    connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(cancelBtn_slot()));
    connect(ui->finishBtn, SIGNAL(clicked()), this, SLOT(finishBtn_slot()));
}

void ControlScreen::cancelBtn_slot()
{
    emit cancel_save_screen();
}

void ControlScreen::finishBtn_slot()
{
    emit finish_save_screen();
    emit cancel_save_screen();
}


