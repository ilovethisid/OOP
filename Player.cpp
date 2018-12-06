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
    this->maxspd=20;
}

void Player::applyGravity()
{
    this->yspd+=1;
}

void Player::applyFriction()
{
    if(this->xspd<-2)
    {
        this->xspd+=3;
    }
    else if(this->xspd>2)
    {
        this->xspd-=3;
    }
    else
    {
        this->xspd=0;
    }
}


