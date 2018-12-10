#pragma once

#include "GameTimer.h"

#include <QGraphicsRectItem>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsScene>

class StartMenu:public QGraphicsScene
{
private:
    GameTimer* timer;
    QGraphicsTextItem* text;

    void displayText();
    void displayButton();

public:
    QPushButton* button;

    StartMenu(int WINWIDTH,int WINHEIGHT);

signals:
    void Sound_button();
};


class RespawnButton:public QPushButton
{
public:
    RespawnButton(QString str);
};

class GameoverLayer:public QGraphicsRectItem
{
private:
    QGraphicsTextItem* text;

public:
    RespawnButton* button;

    GameoverLayer();

    void display(int originX,int originY,int WINWIDTH,int WINHEIGHT);

signals:
    void Sound_button();
};

class EndingScene:public QGraphicsScene
{
private:
    GameTimer* timer;
    QGraphicsTextItem* text;

    void displayText();
    void displayButton();

public:
    QPushButton* button;

    EndingScene(int WINWIDTH,int WINHEIGHT);

signals:
    void Sound_button();
};

