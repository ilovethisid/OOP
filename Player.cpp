#include "Player.h"

#include <math.h>
#include <Windows.h>

Player::Player(int x,int y)
{
    this->setPos(x,y);
    this->setRect(0,0,50,50);
    this->w=50;
    this->h=50;
    this->xspd=0;
    this->yspd=0;
}

void Player::move()
{
    this->setPos(this->x()+this->xspd,this->y()+this->yspd);
}

void Player::applyGravity()
{
    this->yspd+=1;
}

void Player::applyFriction()
{
    if(this->xspd<0)
    {
        this->xspd++;
    }
    else if(this->xspd>0)
    {
        this->xspd--;
    }
}


