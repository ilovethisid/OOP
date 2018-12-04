#pragma once

#include "Pos.h"

#include <QGraphicsRectItem>

class Block: public QGraphicsRectItem
{
private:
    int x,y;

public:
    int w,h; // width and height
    Pos center;

    Block(int x,int y,int w,int h);
};
