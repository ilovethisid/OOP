#pragma once

#include <QGraphicsRectItem>
#include <QLabel>

class GameoverLayer:public QGraphicsRectItem
{
public:
    QGraphicsTextItem* text;

    GameoverLayer();
};

