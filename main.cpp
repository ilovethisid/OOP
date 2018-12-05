#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDesktopWidget>
#include <QDebug>
#include <Windows.h>
#include <QGraphicsRectItem>

#include "Player.h"
#include "window.h"
#include "block.h"
#include "Map.h"

#define FPS 30

void gamestart(Player*);

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    // create a scene
    Map* map = new Map();

    // create a window
    Window* win=new Window(map);

    // add a window
    win->show();
    map->setSceneRect(0,0,WINWIDTH,WINHEIGHT);



    return app.exec();
}






