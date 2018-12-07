#include "Interface.h"

#include <QColor>
#include <QBrush>

GameoverLayer::GameoverLayer()
{
    this->setBrush(QBrush(QColor(105,105,105,150),Qt::SolidPattern));
    text=new QGraphicsTextItem("You Died",this);
}


