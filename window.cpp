#include "Window.h"
#include "MyFunc.h"

#include <QStyle>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <math.h>

Window::Window(Map* map,GameTimer* timer) :QGraphicsView(map)
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFixedSize(WINWIDTH,WINHEIGHT);
    this->setWindowTitle("temp title");

    // place window in center
    this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));

    // window center
    this->player=map->player;

    // game timer
    this->timer=timer;
    connect(this->timer,&QTimer::timeout,this,&Window::centerOnPlayer);

    // mouse
    mouseInitX=0;
    mouseInitY=0;
    m_nPTargetPixmap=new QPixmap(400,400);

    test();
}

void Window::centerOnPlayer()
{
    // always center on player
    this->centerOn(this->player);
}

void Window::mousePressEvent(QMouseEvent* e)
{
    mouseInitX=e->pos().x();
    mouseInitY=e->pos().y();
}

void Window::mouseMoveEvent(QMouseEvent* e)
{
    if(e->type()==QEvent::MouseMove)
    {

    }
}

void Window::mouseReleaseEvent(QMouseEvent* e)
{
    mouseFinalX=e->pos().x();
    mouseFinalY=e->pos().y();

    int distX=mouseFinalX-mouseInitX;
    int distY=mouseFinalY-mouseInitY;
    int spdX=int(distX/5);
    int spdY=int(distY/5);

    if(abs(spdX)>20)
    {
        spdX=sign(spdX)*20;
    }
    if(abs(spdY)>20)
    {
        spdY=sign(spdY)*20;
    }

    this->player->xspd=spdX;
    this->player->yspd=spdY;
}




