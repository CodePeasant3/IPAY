#include "advancedfunction.h"
#include "ui_advancedfunction.h"

AdvancedFunction::AdvancedFunction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdvancedFunction)
{
    ui->setupUi(this);
}

AdvancedFunction::~AdvancedFunction()
{
    delete ui;
}
