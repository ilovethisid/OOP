#pragma once

#include <QGraphicsRectItem>

class Block: public QGraphicsRectItem
{
public:
    int x,y;
    int w,h; // width and height

    Block();
    Block(int x,int y,int w,int h);
};
