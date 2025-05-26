#include "keyboardmousetemplate.h"
#include "ui_keyboardmousetemplate.h"

KeyboardMouseTemplate::KeyboardMouseTemplate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KeyboardMouseTemplate)
{
    ui->setupUi(this);
}

KeyboardMouseTemplate::~KeyboardMouseTemplate()
{
    delete ui;
}

void KeyboardMouseTemplate::Init(int index,std::string labelContext,ipay::ScenePlaybackType type)
{
    QPixmap pixmap("://Resources/image/km_close.png");
    pixmap = pixmap.scaled(ui->label_context->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_context->setAlignment(Qt::AlignCenter);
    ui->label_close->setPixmap(pixmap);

    index_ = index;
    type_ = type;
    ui->label_context->setText(QString::fromStdString(labelContext));
    ui ->label_num ->setAlignment(Qt::AlignCenter);
    ui ->label_num ->setText(QString::number(index_));

    connect(ui->label_close,&ClickableLabel::clicked,[this](){
        emit clickClose(this->type_,this->index_);
    });


}

