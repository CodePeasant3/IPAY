#include "miscellaneousfunction.h"
#include "ui_miscellaneousfunction.h"

MiscellaneousFunction::MiscellaneousFunction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MiscellaneousFunction)
{
    ui->setupUi(this);
}

MiscellaneousFunction::~MiscellaneousFunction()
{
    delete ui;
}
