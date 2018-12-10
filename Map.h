#pragma once

#include "block.h"
#include "Player.h"
#include "GameTimer.h"
#include "Interface.h"

#include <QGraphicsScene>
#include <QList>
#include <QKeyEvent>

#define MAPWIDTH 4000
#define MAPHEIGHT 5500

class Map:public QGraphicsScene
{
    Q_OBJECT
private:
    QList<Block*> blocks;
    GameTimer* timer;
    Block* endblock;

public:
    Player* player;
    GameoverLayer* gameoverLayer;

    Map(GameTimer* timer);

    void addBlock(Block* newblock);

    bool checkPlayerLeftCollision();
    bool checkPlayerRightCollision();
    bool checkPlayerTopCollision();
    bool checkPlayerBotCollision();

    bool playerSideMove();
    bool playerVertMove();

    void keyPressEvent(QKeyEvent* e);
    void blockInit();

private slots:
    void update();
    void respawn();

signals:
    void gameover();
    void gameend();
    void sound_drop();
    void sound_button();
};





