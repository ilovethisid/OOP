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
    int maxspd;

    Player(int x,int y);

    void applyGravity();
    void applyFriction();
};

