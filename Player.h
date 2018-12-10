#pragma once

#include "block.h"

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QObject>

#define PLAYER_START_X MAPWIDTH/2
#define PLAYER_START_Y MAPHEIGHT-100

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
    void respawn();
};

