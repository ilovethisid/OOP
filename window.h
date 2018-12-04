#pragma once

#include <QGraphicsView>
#include <QGraphicsScene>

#define WINWIDTH 800
#define WINHEIGHT 600

class Window: public QGraphicsView
{
public:
    Window(QGraphicsScene* scene);
};
