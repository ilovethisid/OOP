#pragma once

#include "block.h"
#include "Player.h"
#include "GameTimer.h"
#include "Interface.h"

#include <QGraphicsScene>
#include <QList>
#include <QKeyEvent>

#define MAPWIDTH 4000
#define MAPHEIGHT 8000

class Map:public QGraphicsScene
{
private:
    QList<Block*> blocks;
    GameTimer* timer;

    void blockInit();

public:
    Player* player;
    GameoverLayer* gameoverLayer;
    bool gameover;

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





