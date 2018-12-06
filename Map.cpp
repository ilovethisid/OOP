#include "Map.h"

#include <QDebug>
#include <math.h>

Map::Map(GameTimer* timer)
{
    this->player=new Player(MAPWIDTH/2,MAPHEIGHT-300);
    this->addItem(player);

    this->timer=timer;
    connect(this->timer,&QTimer::timeout,this,&Map::update);

    blockInit(); // create all block
}

void Map::update()
{
    if(!this->checkPlayerBotCollision())
    {
        // on the air
        this->player->applyGravity();
    }
    else if(this->checkPlayerBotCollision())
    {
        // on the ground
        this->player->applyFriction();
    }

    playerSideMove();
    playerVertMove();
}

void Map::addBlock(Block* newblock)
{
    this->blocks.append(newblock);
    this->addItem(newblock);
}

bool Map::checkPlayerLeftCollision()
{
    double blockRight;
    double blockTop,blockBot;

    double playerLeft;
    double playerTop,playerBot;

    playerLeft=player->x();
    playerTop=player->y();
    playerBot=player->y()+player->h;

    for(int i=0;i<blocks.size();i++)
    {
        // check if player collides with block

        blockRight=blocks.at(i)->x+blocks.at(i)->w;
        blockTop=blocks.at(i)->y;
        blockBot=blocks.at(i)->y+blocks.at(i)->h;

        if(!(playerTop>=blockBot || playerBot<=blockTop))
        {
            if(int(playerLeft)==int(blockRight))
            {
                // player collides with block
                return true;
            }
        }
    }

    return false;
}

bool Map::checkPlayerRightCollision()
{
    double blockLeft;
    double blockTop,blockBot;

    double playerRight;
    double playerTop,playerBot;

    playerRight=player->x()+player->w;
    playerTop=player->y();
    playerBot=player->y()+player->h;

    for(int i=0;i<blocks.size();i++)
    {
        // check if player collides with block

        blockLeft=blocks.at(i)->x;
        blockTop=blocks.at(i)->y;
        blockBot=blocks.at(i)->y+blocks.at(i)->h;

        if(!(playerTop>=blockBot || playerBot<=blockTop))
        {
            if(int(playerRight)==int(blockLeft))
            {
                // player collides with block
                return true;
            }
        }
    }

    return false;
}

bool Map::checkPlayerTopCollision()
{
    double blockLeft,blockRight;
    double blockBot;

    double playerLeft,playerRight;
    double playerTop;

    playerLeft=player->x();
    playerRight=player->x()+player->w;
    playerTop=player->y();

    for(int i=0;i<blocks.size();i++)
    {
        // check if player is under the ceiling

        blockLeft=blocks.at(i)->x;
        blockRight=blocks.at(i)->x+blocks.at(i)->w;
        blockBot=blocks.at(i)->y+blocks.at(i)->h;

        if(!(playerLeft>=blockRight || playerRight<=blockLeft))
        {
            if(int(blockBot)==int(playerTop))
            {
                // player is under the ceiling
                return true;
            }
        }
    }

    return false;
}

bool Map::checkPlayerBotCollision()
{
    double blockLeft,blockRight;
    double blockTop;

    double playerLeft,playerRight;
    double playerBot;

    playerLeft=player->x();
    playerRight=player->x()+player->w;
    playerBot=player->y()+player->h;

    for(int i=0;i<blocks.size();i++)
    {
        // check if player is on a block

        blockLeft=blocks.at(i)->x;
        blockRight=blocks.at(i)->x+blocks.at(i)->w;
        blockTop=blocks.at(i)->y;

        if(!(playerLeft>=blockRight || playerRight<=blockLeft))
        {
            if(int(blockTop)==int(playerBot))
            {
                // player is on the block
                return true;
            }
        }
    }

    return false;
}



bool Map::playerSideMove()
{
    if(player->xspd<0)
    {
        // moving left

        for(int i=0;i<abs(player->xspd);i++)
        {
            // move xspd amount until player hits the block

            if(checkPlayerLeftCollision())
            {
                if(abs(player->xspd)>5)
                {
                    player->xspd=int(-0.5*player->xspd);
                    // bounce
                }
                else
                {
                    player->xspd=0;
                }

                return true;
            }

            player->setPos(player->x()-1,player->y());
        }
    }

    else if(player->xspd>0)
    {
        // moving right

        for(int i=0;i<player->xspd;i++)
        {
            // move xspd amount until player hits the block

            if(checkPlayerRightCollision())
            {
                if(abs(player->xspd)>5)
                {
                    player->xspd=int(-0.5*player->xspd);
                    // bounce
                }
                else
                {
                    player->xspd=0;
                }

                return true;
            }

            player->setPos(player->x()+1,player->y());
        }
    }

    return false;
}

bool Map::playerVertMove()
{
    if(player->yspd>0)
    {
        // moving down

        for(int i=0;i<player->yspd;i++)
        {
            // move yspd amount until player hits the ground

            if(checkPlayerBotCollision())
            {
                if(abs(player->yspd)>5)
                {
                    player->yspd=int(-0.5*player->yspd);
                    // bounce
                }
                else
                {
                    player->yspd=0;
                }

                return true;
            }

            player->setPos(player->x(),player->y()+1);
        }
    }

    else if(player->yspd<0)
    {
        // moving up

        for(int i=0;i<abs(player->yspd);i++)
        {
            // move yspd amount until player hits the ceiling

            if(checkPlayerTopCollision())
            {
                if(abs(player->yspd)>5)
                {
                    player->yspd=int(-0.5*player->yspd);
                    // bounce
                }
                else
                {
                    player->yspd=0;
                }

                return true;
            }

            player->setPos(player->x(),player->y()-1);
        }
    }

    return false;
}

void Map::blockInit()
{
    Block* ground=new Block(0,MAPHEIGHT-10,MAPWIDTH,10);      // ground
    Block* leftwall=new Block(0,0,10,MAPHEIGHT-10);           // left wall
    Block* rightwall=new Block(MAPWIDTH-10,0,1,MAPHEIGHT-10); // right wall
    Block* block1=new Block(MAPWIDTH/2-1100,MAPHEIGHT-100,250,10);
    Block* block2=new Block(MAPWIDTH/2-750,MAPHEIGHT-100,180,20);
    Block* block3=new Block(MAPWIDTH/2-300,MAPHEIGHT-100,150,30);
    Block* block4=new Block(MAPWIDTH/2+100,MAPHEIGHT-100,120,30);
    Block* block5=new Block(MAPWIDTH/2+420,MAPHEIGHT-100,200,25);
    Block* block6=new Block(MAPWIDTH/2+800,MAPHEIGHT-100,180,10);
    Block* block7=new Block(MAPWIDTH/2-900,MAPHEIGHT-250,300,20);
    Block* block8=new Block(MAPWIDTH/2-400,MAPHEIGHT-200,260,10);
    Block* block9=new Block(MAPWIDTH/2+150,MAPHEIGHT-200,100,15);
    Block* block10=new Block(MAPWIDTH/2+650,MAPHEIGHT-250,250,10);
    Block* block11=new Block(MAPWIDTH/2-900,MAPHEIGHT-350,280,10);
    Block* block12=new Block(MAPWIDTH/2-500,MAPHEIGHT-350,300,10);
    Block* block13=new Block(MAPWIDTH/2+200,MAPHEIGHT-380,250,20);
    Block* block14=new Block(MAPWIDTH/2+850,MAPHEIGHT-370,200,10);
    Block* block15=new Block(MAPWIDTH/2-1000,MAPHEIGHT-450,250,10);
    Block* block16=new Block(MAPWIDTH/2-1190,MAPHEIGHT-300,150,10);
    Block* block17=new Block(MAPWIDTH/2-1100,MAPHEIGHT-600,150,10);
    Block* block18=new Block(MAPWIDTH/2-750,MAPHEIGHT-650,300,30);
    Block* block19=new Block(MAPWIDTH/2-700,MAPHEIGHT-680,250,30);
    Block* block20=new Block(MAPWIDTH/2-600,MAPHEIGHT-710,100,30);
    Block* block21=new Block(MAPWIDTH/2-550,MAPHEIGHT-740,50,30);
    Block* block22=new Block(MAPWIDTH/2,MAPHEIGHT-500,300,10);
    Block* block23=new Block(MAPWIDTH/2+700,MAPHEIGHT-600,350,30);
    Block* block24=new Block(MAPWIDTH/2+800,MAPHEIGHT-620,150,20);
    Block* block25=new Block(MAPWIDTH/2+900,MAPHEIGHT-800,10,180);
    Block* block26=new Block(MAPWIDTH/2+400,MAPHEIGHT-550,250,10);
    Block* block27=new Block(MAPWIDTH/2-400,MAPHEIGHT-500,200,10);
    Block* block28=new Block(MAPWIDTH/2-1100,MAPHEIGHT-900,400,20);
    Block* block29=new Block(MAPWIDTH/2-600,MAPHEIGHT-1000,250,50);
    Block* block30=new Block(MAPWIDTH/2-100,MAPHEIGHT-850,150,20);
    Block* block31=new Block(MAPWIDTH/2-200,MAPHEIGHT-650,250,30);/*
    Block* block32=new Block(MAPWIDTH/2-100,MAPHEIGHT-850,150,20);
    Block* block33=new Block(MAPWIDTH/2-100,MAPHEIGHT-850,150,20);
    Block* block34=new Block(MAPWIDTH/2-100,MAPHEIGHT-850,150,20);
    Block* block35=new Block(MAPWIDTH/2-100,MAPHEIGHT-850,150,20);
    Block* block36=new Block(MAPWIDTH/2-100,MAPHEIGHT-850,150,20);
    Block* block37=new Block(MAPWIDTH/2-100,MAPHEIGHT-850,150,20);
    Block* block38=new Block(MAPWIDTH/2-100,MAPHEIGHT-850,150,20);
    Block* block39=new Block(MAPWIDTH/2-100,MAPHEIGHT-850,150,20);
    Block* block40=new Block(MAPWIDTH/2-100,MAPHEIGHT-850,150,20);
    Block* block41=new Block(MAPWIDTH/2-100,MAPHEIGHT-850,150,20);
    Block* block42=new Block(MAPWIDTH/2-100,MAPHEIGHT-850,150,20);*/

    // add the item to the map
    this->addBlock(ground);
    this->addBlock(leftwall);
    this->addBlock(rightwall);
    this->addBlock(block1);
    this->addBlock(block2);
    this->addBlock(block3);
    this->addBlock(block4);
    this->addBlock(block5);
    this->addBlock(block6);
    this->addBlock(block7);
    this->addBlock(block8);
    this->addBlock(block9);
    this->addBlock(block10);
    this->addBlock(block11);
    this->addBlock(block12);
    this->addBlock(block13);
    this->addBlock(block14);
    this->addBlock(block15);
    this->addBlock(block16);
    this->addBlock(block17);
    this->addBlock(block18);
    this->addBlock(block19);
    this->addBlock(block20);
    this->addBlock(block21);
    this->addBlock(block22);
    this->addBlock(block23);
    this->addBlock(block24);
    this->addBlock(block25);
    this->addBlock(block26);
    this->addBlock(block27);
    this->addBlock(block28);
    this->addBlock(block29);
    this->addBlock(block30);
    this->addBlock(block31);
}



