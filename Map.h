#pragma once

#include "block.h"
#include "Player.h"
#include "Gametimer.h"

#include <QGraphicsScene>
#include <QList>
#include <QTimer>
#include <QObject>
#include <QKeyEvent>

#define FPS 30
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

    void drawBackground();
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
