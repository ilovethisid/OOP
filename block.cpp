#include "block.h"

Block::Block(int x,int y,int w,int h)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
    this->setRect(x,y,w,h);
}
