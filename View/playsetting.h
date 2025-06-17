#ifndef PLAYSETTING_H
#define PLAYSETTING_H

#include <QWidget>
#include <QListWidgetItem>
#include <QPushButton>
#include <QAbstractItemDelegate>
#include <QApplication>
#include <QMouseEvent>
#include <qDebug>
#include <QStandardItemModel>
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QFont>
#include <QSize>
#include <QStyledItemDelegate>
#include <QMapIterator>
#include "../Common/primaryscreen.h"
#include <QLayout>
#include "Common/savesettingstruct.h"

namespace Ui {
class PlaySetting;
}

class PlaySetting : public QWidget
{
    Q_OBJECT

public:
    explicit PlaySetting(QWidget *parent = nullptr);
    ~PlaySetting();
    void init();
    void exit();

signals:
    void start_keyboard_record();
    void AllowOperation();
    void stop_record_keyboard();

private slots:
    void OnItemSelectionChanged();
    void closeEvent(QCloseEvent *event) override;


private:
    Ui::PlaySetting *ui;
    QListWidgetItem   *cashRegisterSetting_;
    QListWidgetItem   *reminderSetting_;
    QListWidgetItem   *scanCodeSetting_;
    QListWidgetItem   *commonSetting_;
    QListWidgetItem   *miscellaneousFunction_;
    QListWidgetItem   *advancedFunction_;
    QMap<int,QWidget*> mapWidgetItem_;

};


class CustomDelegate : public QStyledItemDelegate
{
public:
    CustomDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent) {}
    QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const override
    {
        QSize size = QStyledItemDelegate::sizeHint(option, index);
        // 获取QListWidget的宽度作为QListWidgetItem的宽度
        const QObject* constObj = option.widget;
        QObject* nonConstObj = const_cast<QObject*>(constObj);
        QWidget* listWidget = qobject_cast<QWidget*>(nonConstObj);
        if (listWidget)
        {
            int listWidgetWidth = listWidget->width();
            size.setWidth(listWidgetWidth);
        }
        return size;
    }


    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override
       {
           QStyleOptionViewItem newOption = option;
           newOption.showDecorationSelected = true;

           QStyledItemDelegate::paint(painter, newOption, index);
       }

};

#endif // PLAYSETTING_H
