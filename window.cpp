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
    this->lineLength=0;
    maxLength=10*player->maxspd;
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

    if(e->type()==QEvent::MouseMove && map->checkPlayerBotCollision())
    {
        startX=int(mapToScene(QPoint(mouseInitX,mouseInitY)).x());
        startY=int(mapToScene(QPoint(mouseInitX,mouseInitY)).y());
        endX=int(mapToScene(QPoint(e->pos())).x());
        endY=int(mapToScene(QPoint(e->pos())).y());

        length=int(sqrt(pow(startX-endX,2)+pow(startY-endY,2)));

        QPen* pen=new QPen(Qt::black,5,Qt::DashLine);
        if(length<=maxLength)
        {
            pen->setColor(QColor(int(255*double(length/double(maxLength))),0,100));
        }
        else
        {
            pen->setColor(Qt::red);
        }

        line->setPen(*pen);
        pen->setColor(Qt::black);
        projection->setPen(*pen);

        int playerX=int(player->x()+player->w/2);
        int playerY=int(player->y()+player->h/2);
        // player center x,y

        if(length>maxLength)
        {
            endX=startX+int((endX-startX)*double(maxLength/double(length)));
            endY=startY+int((endY-startY)*double(maxLength/double(length)));
            line->setLine(startX,startY,endX,endY);
            projection->setLine(playerX,playerY,playerX+endX-startX,playerY+endY-startY);
            line->show();
            projection->show();
            lineLength=maxLength;
        }
        else
        {
            line->setLine(startX,startY,endX,endY);
            projection->setLine(playerX,playerY,playerX+endX-startX,playerY+endY-startY);
            line->show();
            projection->show();
            lineLength=length;
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
        double angle=atan2(distY,distX);

        int spdX=int(player->maxspd*cos(angle)*double(lineLength/double(maxLength)));
        int spdY=int(player->maxspd*sin(angle)*double(lineLength/double(maxLength))); // because of computer's coordinate system

        this->player->xspd=spdX;
        this->player->yspd=spdY;
    }

    line->hide();
    projection->hide();
}









