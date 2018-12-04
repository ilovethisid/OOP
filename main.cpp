#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QStyle>
#include <QDesktopWidget>
#include <QList>
#include <QDebug>

#include "Player.h"
#include "window.h"
#include "block.h"

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    // create a scene
    QGraphicsScene* scene = new QGraphicsScene();

    // create a window
    Window* win=new Window(scene);

    //create an item to put into the scene
    Player* player = new Player(WINWIDTH/2,WINHEIGHT/2);
    player->setRect(0,0,50,50);

    Block* block=new Block(WINWIDTH/2,WINHEIGHT-100,100,50);

    // add the item to the scene
    scene->addItem(player);
    scene->addItem(block);

    // add a window
    win->show();
    scene->setSceneRect(0,0,WINWIDTH,WINHEIGHT);

    // make player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    return app.exec();
}





