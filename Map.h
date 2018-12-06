#pragma once

#include "block.h"
#include "Player.h"
#include "GameTimer.h"

#include <QGraphicsScene>
#include <QList>
#include <QKeyEvent>

#define MAPWIDTH 2400
#define MAPHEIGHT 2000

class Map:public QGraphicsScene
{
private:
    QList<Block*> blocks;
    GameTimer* timer;

    void blockInit();

public:
    Player* player;

    Map(GameTimer* timer);

    void addBlock(Block* newblock);

    bool checkPlayerLeftCollision();
    bool checkPlayerRightCollision();
    bool checkPlayerTopCollision();
    bool checkPlayerBotCollision();

    bool playerSideMove();
    bool playerVertMove();

private slots:
    void update();
};
