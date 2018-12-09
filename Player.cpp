#include "Player.h"

#include <math.h>
#include <Windows.h>
#include <QBrush>

Player::Player(int x,int y)
{
    this->setPos(x,y);
    this->setRect(0,0,30,30);
    this->w=30;
    this->h=30;
    this->xspd=0;
    this->yspd=0;
    this->setBrush(Qt::black);
    this->setPen(QPen(Qt::white,2));
    this->isAlive=true;
}

int Player::maxspd=20;
int Player::maxfallspd=40;
int Player::deathspd=30;

void Player::applyGravity()
{
    if(this->yspd<maxfallspd)
    {
        this->yspd+=1;
    }
}

void Player::applyFriction()
{
    if(this->xspd<-1)
    {
        this->xspd+=2;
    }
    else if(this->xspd>1)
    {
        this->xspd-=2;
    }
    else
    {
        this->xspd=0;
    }
}

void Player::die()
{
    this->isAlive=false;
    this->setBrush(Qt::red);
    this->xspd=0;
    this->yspd=0;
}

void Player::respawn()
{
    this->isAlive=true;
    this->setBrush(Qt::black);
    this->setPen(QPen(Qt::white,2));
}


