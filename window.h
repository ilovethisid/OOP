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
    Map* map;
    Player* player;
    int mouseInitX;
    int mouseInitY;
    int mouseFinalX;
    int mouseFinalY;
    QGraphicsLineItem* line;
    QGraphicsLineItem* projection;
    int lineLength;

    void mousePressEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);

public:
    Window(Map* map,GameTimer* timer);

private slots:
    void centerOnPlayer();
};



