#include "Window.h"

#include <QStyle>
#include <QApplication>
#include <QDesktopWidget>

Window::Window(QGraphicsScene* scene) :QGraphicsView(scene)
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFixedSize(WINWIDTH,WINHEIGHT);
    this->setWindowTitle("temp title");

    // place window in center
    this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
}
