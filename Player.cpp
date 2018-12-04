#include "Player.h"

#include <math.h>

Player::Player(int x,int y)
{
    this->setPos(x,y);
    this->xspd=0;
    this->yspd=0;
}

void Player::keyPressEvent(QKeyEvent* event)
{
    if(event->key()==Qt::Key_W)
    {
        if(scene()->collidingItems(this).isEmpty())
        {
            this->moveUp();
        }
    }
    if(event->key()==Qt::Key_A)
    {
        if(scene()->collidingItems(this).isEmpty())
        {
            this->moveLeft();
        }
    }
    if(event->key()==Qt::Key_S)
    {
        if(scene()->collidingItems(this).isEmpty())
        {
            this->moveDown();
        }
    }
    if(event->key()==Qt::Key_D)
    {
        if(scene()->collidingItems(this).isEmpty())
        {
            this->moveRight();
        }
    }
}

void Player::moveUp()
{
    this->setPos(this->x(),this->y()-10);
}

void Player::moveDown()
{
    this->setPos(this->x(),this->y()+10);
}

void Player::moveLeft()
{
    this->setPos(this->x()-10,this->y());
}

void Player::moveRight()
{

    this->setPos(this->x()+10,this->y());
}




