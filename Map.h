#pragma once

#include "Block.h"

#include <QGraphicsScene>

class Map:public QGraphicsScene
{
private:

public:
    Map();

    void addBlock();
};
