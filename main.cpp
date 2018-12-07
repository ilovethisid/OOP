#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QGraphicsRectItem>

#include "Player.h"
#include "window.h"
#include "block.h"
#include "Map.h"
#include "GameTimer.h"

#define FPS 30

void gamestart(Player*);

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    // create a timer
    GameTimer* timer=new GameTimer();

    // create a scene
    Map* map = new Map(timer);

    // create a window
    Window* win=new Window(map,timer);

    // add a window
    win->show();
    map->setSceneRect(0,0,MAPWIDTH,MAPHEIGHT);

    return app.exec();
}






