#include "Player.h"

#include <math.h>
#include <Windows.h>

Player::Player(int x,int y)
{
    this->setPos(x,y);
    this->setRect(0,0,30,30);
    this->w=30;
    this->h=30;
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


