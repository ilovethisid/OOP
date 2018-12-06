#pragma once

#include "block.h"
#include "Player.h"
#include "gametimer.h"

#include <QGraphicsScene>
#include <QList>
#include <QKeyEvent>

#define MAPWIDTH 1200
#define MAPHEIGHT 1200

class Map:public QGraphicsScene
{
private:
    QList<Block*> blocks;
    GameTimer* timer;

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
    void keyPressEvent(QKeyEvent* e);

private slots:
    void update();
};
