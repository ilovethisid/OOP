#pragma once

#include "block.h"
#include "Player.h"

#include <QGraphicsScene>
#include <QList>
#include <QTimer>
#include <QObject>
#include <QKeyEvent>

#define FPS 30
#define MAPWIDTH 800
#define MAPHEIGHT 600

class Map:public QGraphicsScene
{
private:
    QList<Block*> blocks;
    Player* player;
    QTimer* timer;

public:
    Map();

    void addBlock(Block* newblock);
    bool checkSideCollision();
    bool checkVertCollision();
    void keyPressEvent(QKeyEvent* e);

private slots:
    void update();
};
