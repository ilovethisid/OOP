#pragma once

#include "block.h"

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsScene>

class Player: public QGraphicsRectItem
{
private:
    static int maxfallspd;

public:
    int w,h; // width and height
    int xspd,yspd;
    static int maxspd;
    static int deathspd;
    bool isAlive;

    Player(int x,int y);

    void applyGravity();
    void applyFriction();
    void die();
};

