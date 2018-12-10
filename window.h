#pragma once

#include "Player.h"
#include "GameTimer.h"
#include "Map.h"

#include <QGraphicsView>
#include <QGraphicsScene>

#define WINWIDTH 800
#define WINHEIGHT 600

class Window: public QGraphicsView
{
    Q_OBJECT
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

public:
    Window(Map* map,GameTimer* timer);

private slots:
    void centerOnPlayer();
    void showGameoverInterface();
    void gamestart();
    void gameend();
    void regame();

signals:
    void sound_bow_pull();
    void sound_bow_release();
    void sound_button();
};



