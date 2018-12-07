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
    bool mousePressed;
    QGraphicsLineItem* line;
    QGraphicsLineItem* projection;
    int lineLength;
    int maxLength;

    void mousePressEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
    void showGameoverInterface();

public:
    Window(Map* map,GameTimer* timer);

private slots:
    void centerOnPlayer();
};



