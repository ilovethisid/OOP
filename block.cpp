#include "block.h"

#include <QBrush>
#include <QPen>

Block::Block()
{

}

Block::Block(int x,int y,int w,int h)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
    this->setRect(x,y,w,h);
    this->setPen(QPen(Qt::black,2));
}
