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

    // map
    this->map=map;

    // player
    this->player=map->player;

    // game timer
    this->timer=timer;
    connect(this->timer,&QTimer::timeout,this,&Window::centerOnPlayer);

    // mouse
    mouseInitX=0;
    mouseInitY=0;

    // line
    this->line=new QGraphicsLineItem();
    this->map->addItem(line);
    this->projection=new QGraphicsLineItem();
    this->map->addItem(projection);
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
    int startX,startY;
    int endX,endY;
    int length;
    int maxLength;

    if(e->type()==QEvent::MouseMove && map->checkPlayerBotCollision())
    {
        startX=int(mapToScene(QPoint(mouseInitX,mouseInitY)).x());
        startY=int(mapToScene(QPoint(mouseInitX,mouseInitY)).y());
        endX=int(mapToScene(QPoint(e->pos())).x());
        endY=int(mapToScene(QPoint(e->pos())).y());

        length=int(sqrt(pow(startX-endX,2)+pow(startY-endY,2)));
        maxLength=10*player->maxspd;

        QPen* pen=new QPen(Qt::black,5,Qt::DashLine);
        if(length<=maxLength)
        {
            pen->setColor(QColor(int(255*double(length/double(maxLength))),100,100));
        }

        line->setPen(*pen);
        pen->setColor(Qt::black);
        projection->setPen(*pen);

        int playerX=int(player->x()+player->w/2);
        int playerY=int(player->y()+player->h/2);
        // player center x,y

        line->setLine(startX,startY,endX,endY);
        projection->setLine(playerX,playerY,playerX+endX-startX,playerY+endY-startY);

        if(length>maxLength)
        {
            line->hide();
            projection->hide();
        }
        else
        {
            line->show();
            projection->show();
        }
    }
}

void Window::mouseReleaseEvent(QMouseEvent* e)
{
    if(map->checkPlayerBotCollision())
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

    line->hide();
    projection->hide();
}









