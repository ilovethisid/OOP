#pragma once

#include "block.h"

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsScene>

class Player: public QGraphicsRectItem
{
public:
    int w,h; // width and height
    int xspd,yspd;

    Player(int x,int y);

    void move();
    void applyGravity();
    void applyFriction();
};

