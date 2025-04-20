#include "screen.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPainterPath>
#include <QPoint>
#include <QDebug>
#include <QScreen>
#include <QGuiApplication>
#include <QFileDialog>
#include <QRectF>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTime>
#include"myrect.h"

Screen::Screen(QWidget *parent)
    : QWidget(parent),
      widthInfoRect(QRectF(0, 0, 0, 0)),
      control_(NULL)
{
    showFullScreen();//将窗口部件全屏显示

    //截取全屏
    QScreen *scrPix = QGuiApplication::primaryScreen();
    pixmap = scrPix->grabWindow(0);
    //全局路径的初始化，一个全屏闭合回路
    globalPath.lineTo(pixmap.width(), 0);
    globalPath.lineTo(pixmap.width(), pixmap.height());
    globalPath.lineTo(0, pixmap.height());
    globalPath.lineTo(0, 0);

    oncePress = true;
    labelimage=new QSLabel(this);
    Qt::WindowFlags nType = Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint;
    labelimage->setWindowFlags(nType);
    setMouseTracking(true);
    type = NO;

}

void Screen::setControlScreen(ControlScreen *controlUi,QWidget* control)
{
    control_ = control;
    controlUi_ = controlUi;
}

void Screen::paintEvent(QPaintEvent *e)//将上一个函数得到的全屏灰色图绘制在painter上，并添加宽高信息矩形和边角拖曳小正方形
{


    QPainter paint(this);
    paint.drawPixmap(0, 0, pixmap);
    //初始化画笔操作
    paint.setPen(Qt::blue);
    paint.setBrush(QColor(0, 0, 0, 100));
    //设置路径
    QPainterPath path = GetPath();

    paint.drawPath(path);
    //绘制选取左上角显示宽高的区域
    widthInfoRect.drawMe(paint);
    //绘制四个小正方形
    drawControlArea(paint);

}
//绘制正方形
void Screen::drawControlArea(QPainter &painter)//已看懂
{
    //计算四个小正方形
    rect1.setX(movePoint.x() - 3);
    rect1.setY(pressedPoint.y() - 3);
    rect1.setWidth(6);
    rect1.setHeight(6);
    rect2.setX(pressedPoint.x() - 3);
    rect2.setY(pressedPoint.y() - 3);
    rect2.setWidth(6);
    rect2.setHeight(6);
    rect3.setX(pressedPoint.x() - 3);
    rect3.setY(movePoint.y() - 3);
    rect3.setWidth(6);
    rect3.setHeight(6);
    rect4.setX(movePoint.x() - 3);
    rect4.setY(movePoint.y() - 3);
    rect4.setWidth(6);
    rect4.setHeight(6);
    painter.save();
    painter.setBrush(Qt::blue);
    painter.drawRect(rect1);
    painter.drawRect(rect2);
    painter.drawRect(rect3);
    painter.drawRect(rect4);
    painter.restore();
}



//得到选区之外的路径
QPainterPath Screen::GetPath()   //这个函数得到的是开始截图时候得到的白色选区
{
    //选取路径
    QPainterPath path;
    path.moveTo(pressedPoint.x(), pressedPoint.y());
    path.lineTo(movePoint.x(), pressedPoint.y());
    path.lineTo(movePoint.x(), movePoint.y());
    path.lineTo(pressedPoint.x(), movePoint.y());
    path.lineTo(pressedPoint.x(), pressedPoint.y());
    return globalPath.subtracted(path);    //从灰色全屏路径中扣掉这个白色路径区域，然后作为截取的图片？
}


void Screen::mousePressEvent(QMouseEvent *e)
{
    if( e->button() & Qt::LeftButton && oncePress)   //如果鼠标左键第一次按下
    {
       pressedPoint = e->pos();
    } else
    {
        oldPoint = e->pos();
    }
}

void Screen::mouseReleaseEvent(QMouseEvent *e)    //只有已经按下鼠标按键，才会存在鼠标释放行为，释放鼠标后会立刻出现控制面板
{
    oncePress = false;
    if( !control_ )        //如果未出现截图操作控件
    {
        qDebug() << "new ControlScreen";   //新建一个窗口控件
        QHBoxLayout *layout = new QHBoxLayout(control_);    //在control上建立水平布局
        layout->addWidget(controlUi_);         //将控制窗口应用于水平布局
        layout->setContentsMargins(0, 0, 0, 0);
        control_->setObjectName("control");
        control_->setStyleSheet("QWidget#control{\
                               background-color: #eaecf0;}");
    }
    //设置控制面板的位置
    control_->setGeometry(movePoint.x() - 543, movePoint.y() + 6, 543, 25);
    control_->show();
}

void Screen::mouseMoveEvent(QMouseEvent *e)
{
    QPoint tempPoint = e->pos();     //当前鼠标位置
    setselectimagelabel(e);

    if(e->buttons() & Qt::LeftButton)   //如果左键按下
    {
        //选取左上角的信息更改
        int x = qAbs(movePoint.x() - pressedPoint.x());//movepoint即终点坐标
        int y = qAbs(movePoint.y() - pressedPoint.y());
        widthInfoRect.setText(tr("%1 * %2").arg(x).arg(y));   //将截图选区的长宽信息显示在widthinforect中
        if( ComparePoint(pressedPoint, movePoint)) {
            widthInfoRect.setLocation(pressedPoint.x(), pressedPoint.y());
            //计算选区矩形
            rect.setX(pressedPoint.x());
            rect.setY(pressedPoint.y());
            rect.setWidth(movePoint.x() - pressedPoint.x());
            rect.setHeight(movePoint.y() - pressedPoint.y());
        } else {
            widthInfoRect.setLocation(movePoint.x(), movePoint.y());
            rect.setX(movePoint.x());
            rect.setY(movePoint.y());
            rect.setWidth(pressedPoint.x() - movePoint.x());
            rect.setHeight(pressedPoint.y() - movePoint.y());
        }
        if( oncePress )    //如果是第一次按下时候，
        {
            movePoint = e->pos();   //终点即为鼠标此时位置
        //此时的移动代表选区的变化
        } else
        {

            if( control_ )  //如果控制面板已经出现，则第二次以后的每一次鼠标按键都会使其暂时隐藏
                control_->hide();
            int moveX = tempPoint.x() - oldPoint.x();  //鼠标移动的x距离
            int moveY = tempPoint.y() - oldPoint.y();   //鼠标移动的y距离
            switch( type )         //选区角落四个小矩形的位置
            {
            case RECT1:               //意思是第一次选区之后，分别拖动四个角落的小矩形时候，截图选区的变化
                pressedPoint.setY(pressedPoint.y() + moveY);  //右上角的矩形
                movePoint.setX(movePoint.x() + moveX);
                break;
            case RECT2:
                pressedPoint.setX(pressedPoint.x() + moveX);    //左上角的矩形
                pressedPoint.setY(pressedPoint.y() + moveY);
                break;
            case RECT3:
                pressedPoint.setX(pressedPoint.x() + moveX);  //左下角的矩形
                movePoint.setY(movePoint.y() + moveY);
                break;
            case RECT4:
                movePoint.setX(movePoint.x() + moveX);     //右下角的矩形
                movePoint.setY(movePoint.y() + moveY);
                break;
            case RECT0:                  //指的是当鼠标在截图选区中按下左键然后拖动时候，截图选区的整体位置变化
            {

                int tempPressX = pressedPoint.x() + moveX;
                int tempPressY = pressedPoint.y() + moveY;
                int tempMoveX = movePoint.x() + moveX;
                int tempMoveY = movePoint.y() + moveY;
                int deskWidth = pixmap.width();
                int deskHeight = pixmap.height();
                if( tempPressX < 0 )
                {
                    tempPressX = 0;
                    tempMoveX = movePoint.x();
                }
                if( tempPressX > deskWidth)
                {
                    tempPressX = deskHeight;
                }
                if(tempPressY < 0)
                {
                    tempPressY = 0;
                    tempMoveY = movePoint.y();
                }
                if( tempPressY > deskHeight)
                {

                    tempPressY = deskHeight;
                }
                if( tempMoveX < 0)
                {
                    tempMoveX = 0;
                }
                if( tempMoveX > deskWidth)
                {
                    tempMoveX = deskWidth;
                    tempPressX = pressedPoint.x();
                }
                if( tempMoveY < 0)
                {
                    tempMoveY = 0;
                }
                if( tempMoveY > deskHeight)
                {
                    tempMoveY = deskHeight;
                    tempPressY = pressedPoint.y();

                }
                pressedPoint.setX(tempPressX);    //鼠标在截图区域中拖动结束后，选区的位置
                pressedPoint.setY(tempPressY);
                movePoint.setX(tempMoveX);
                movePoint.setY(tempMoveY);
                break;
            }
            case NO:
                break;
            default:
                break;
            }
            oldPoint = tempPoint;    //更新位置坐标信息
        }

    } else                          //指的是当鼠标位于四个角落小矩形中和选区中时候鼠标的图标变化
    {
        Type r = PointInWhere(e->pos());
        if( r == RECT1)
        {
            type = RECT1;
            setCursor(Qt::SizeBDiagCursor);
        } else if( r == RECT2)
        {
            type = RECT2;
            setCursor(Qt::SizeFDiagCursor);
        } else if( r == RECT3)
        {
            type = RECT3;
            setCursor(Qt::SizeBDiagCursor);
        } else if( r == RECT4)
        {
            type = RECT4;
            setCursor(Qt::SizeFDiagCursor);
        } else if( r == RECT0)
        {
            type = RECT0;
            setCursor(Qt::SizeAllCursor);
        } else
        {
            type = NO;
            setCursor(Qt::ArrowCursor);
        }
    }
    repaint();


}

bool Screen::CompareRect(QRectF &r1, QRectF &r2)
{
    return false;
}

//计算此时鼠标移动在哪个选区上面
Type Screen::PointInWhere(QPoint p)
{
    if( pointInRect(p, rect1))
        return RECT1;
    else if( pointInRect(p, rect2))
        return RECT2;
    else if( pointInRect(p, rect3))
        return RECT3;
    else if( pointInRect(p, rect4))
        return RECT4;
    else if( pointInRect(p, rect))
        return RECT0;
    else
        return NO;

}

//判断点是否在矩形之内
bool Screen::pointInRect(QPoint &p, QRectF &r)
{
    if( p.x() > r.x() && p.x() < r.x() + r.width() &&
            p.y() > r.y() && p.y() < r.y() + r.height())
        return true;
    return false;
}

void Screen::keyPressEvent(QKeyEvent *e)    //键盘事件，包括esc退出截图，回车键完成截图，返回键完成截图
{
    int key = e->key();
    switch( key )
    {
    case Qt::Key_Escape :
        close();
        break;
    case Qt::Key_Enter:
        if( controlUi_ )
        {
            controlUi_->finishBtn_slot();
        }
        break;
    case Qt::Key_Return :
        if( controlUi_ )
        {
            controlUi_->finishBtn_slot();
        }
        break;
    default:
        break;
    }
}

//如果p1的x和y坐标都小于p2的x和y坐标返回true
bool Screen::ComparePoint(QPoint &p1, QPoint &p2)      //点p1的位置坐标是否小于p2点
{
    if(p1.x() < p2.x() && p1.y() < p2.y())
        return true;
    return false;
}

void Screen::setselectimagelabel(QMouseEvent* event)
{
    int wid = abs(movePoint.x() - pressedPoint.x());
    int hei = abs(movePoint.y() - pressedPoint.y());
    int x =pressedPoint.x() < movePoint.x() ? pressedPoint.x() : movePoint.x();
    int y =pressedPoint.y() < movePoint.y() ? pressedPoint.y() : movePoint.y();
    QImage selectimage=pixmap.copy(x,y,wid,hei).toImage();
    labelimage->setimagetolabel(selectimage);
    labelimage->setFixedSize(wid,hei);
    labelimage->move(QPoint(x,y));
    labelimage->show();
}

//保存截取出来的图片
void Screen::savePixmap()
{
    QImage pimage=labelimage->resultimage();
}

QPixmap Screen::GetGrabPixmap()
{
    return pixmap.copy(pressedPoint.x(), pressedPoint.y(), movePoint.x() - pressedPoint.x(),
                       movePoint.y() - pressedPoint.y());
}

std::vector<int> Screen::GetPictureCoordinate()
{
    return {pressedPoint.x(),pressedPoint.y(),movePoint.x() - pressedPoint.x(),movePoint.y() - pressedPoint.y()};
}


Screen::~Screen()
{
    Exit();
}

void Screen::Exit()
{
    if(controlUi_){
        controlUi_->hide();
        delete controlUi_;
        controlUi_ = nullptr;
    }
    if(control_){
        control_->hide();
        delete control_;
        control_ = nullptr;
    }
    if(labelimage)
    {
        labelimage->hide();
        delete labelimage;
        labelimage = nullptr;
    }

}
