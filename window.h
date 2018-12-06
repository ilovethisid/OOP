#pragma once

#include "Player.h"
#include "gametimer.h"
#include "Map.h"

#include <QGraphicsView>
#include <QGraphicsScene>

#define WINWIDTH 800
#define WINHEIGHT 600

class Window: public QGraphicsView
{
private:
    GameTimer* timer;
    Player* player;

public:
    Window(Map* map,GameTimer* timer);

private slots:
    void centerOnPlayer();
};



