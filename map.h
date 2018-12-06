#pragma once

#include "block.h"
#include "Player.h"
//#include "mouse.h"

#include <QGraphicsScene>
#include <QList>
#include <QTimer>
#include <QObject>
#include <QKeyEvent>
#include <QMouseEvent>

#include <QWidget>

#define FPS 30
#define MAPWIDTH 800
#define MAPHEIGHT 600

class Map:public QGraphicsScene,public QWidget
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
    void mousePressEvent(QMouseEvent* mouse);

private slots:
    void update();
};
