#pragma once

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsScene>

class Player: public QGraphicsRectItem
{
private:
    int w,h; // width and height
    int xspd,yspd;

public:
    bool collision;

    Player(int x,int y);

    void keyPressEvent(QKeyEvent* event);
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
};

