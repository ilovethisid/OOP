#include "window.h"
#include "MyFunc.h"
#include "Interface.h"

#include <QStyle>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <math.h>
#include <ctime>
#include <QMediaPlayer>

Window::Window(Map* map,GameTimer* timer) :QGraphicsView(map)
{
    // window properties
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
    mousePressed=false;

    // line
    this->line=new QGraphicsLineItem();
    this->map->addItem(line);
    this->projection=new QGraphicsLineItem();
    this->map->addItem(projection);
    this->lineLength=0;
    maxLength=10*player->maxspd;

    // game event
    connect(this->map,&Map::gameover,this,&Window::showGameoverInterface);
    connect(this->map,&Map::gameend,this,&Window::gameend);
}

void Window::centerOnPlayer()
{
    // always center on player
    this->centerOn(this->player);
}

void Window::gameend()
{
    player->setBrush(Qt::yellow);
    player->setPen(QPen(Qt::yellow,2));
    EndingScene* endingScene=new EndingScene(WINWIDTH,WINHEIGHT);
    this->setScene(endingScene);
    endingScene->addItem(player);
    player->setPos(WINWIDTH/2-player->w/2,WINHEIGHT/2-player->h/2);
    connect(endingScene->button,&QPushButton::pressed,this,&Window::regame);
}

void Window::regame()
{
    // basics
    setScene(map);
    timer->start();

    // player init
    player->setPos(PLAYER_START_X,PLAYER_START_Y);
    player->show();
    player->setBrush(Qt::black);
    player->setPen(QPen(Qt::white,2));
    player->xspd=0;
    player->yspd=0;
    map->addItem(player);

    // block init
    map->blockInit();
}

void Window::mousePressEvent(QMouseEvent* e)
{
    mouseInitX=e->pos().x();
    mouseInitY=e->pos().y();
    mousePressed=true;

    QMediaPlayer* mediaPlayer=new QMediaPlayer();
    mediaPlayer->setMedia(QUrl("qrc:/sounds/bow-pull.wav"));
    if(player->isAlive && map->checkPlayerBotCollision())
    {
        // if player is on the ground
        mediaPlayer->play();
    }
}

void Window::mouseMoveEvent(QMouseEvent* e)
{
    int startX,startY;
    int endX,endY;
    int length;

    if(e->type()==QEvent::MouseMove && mousePressed && player->isAlive && map->checkPlayerBotCollision())
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
        if(player->y()<MAPHEIGHT/2)
        {
            pen->setColor(Qt::white);
        }
        else
        {
            pen->setColor(Qt::black);
        }
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
    if(player->isAlive && mousePressed && map->checkPlayerBotCollision())
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

        QMediaPlayer* mediaPlayer=new QMediaPlayer();
        mediaPlayer->setMedia(QUrl("qrc:/sounds/bow-release.mp3"));
        mediaPlayer->play();
    }

    line->hide();
    projection->hide();
    mousePressed=false;
}

void Window::showGameoverInterface()
{
    int originX=int(mapToScene(QPoint(0,0)).x());
    int originY=int(mapToScene(QPoint(0,0)).y());

    map->gameoverLayer->display(originX,originY,WINWIDTH,WINHEIGHT);
}









