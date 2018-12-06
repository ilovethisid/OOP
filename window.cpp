#include "Window.h"

#include <QStyle>
#include <QApplication>
#include <QDesktopWidget>

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
}

void Window::centerOnPlayer()
{
    // always center on player
    this->centerOn(this->player);
}



