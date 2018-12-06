#include "Map.h"

#include <QDebug>
#include <math.h>

int sign(int x);

Map::Map()
{
    this->player=new Player(MAPWIDTH/2,MAPHEIGHT/2);
    this->addItem(player);

    this->timer=new QTimer();
    this->timer->start(1000/FPS);
    connect(this->timer,&QTimer::timeout,this,&Map::update);

    Block* block=new Block(MAPWIDTH/2,MAPHEIGHT-100,100,10);
    Block* block2=new Block(MAPWIDTH/2+50,MAPHEIGHT-200,50,10);
    Block* block3=new Block(MAPWIDTH/2+100,MAPHEIGHT-150,100,10);
    Block* block4=new Block(MAPWIDTH/2-800,MAPHEIGHT-100,10000,20);

    // add the item to the map
    this->addBlock(block);
    this->addBlock(block2);
    this->addBlock(block3);
    this->addBlock(block4);
}

void Map::update()
{
    if(!this->checkVertCollision())
    {
        this->player->applyGravity();
    }
    if(!this->checkSideCollision())
    {
        this->player->applyFriction();
    }
}

void Map::addBlock(Block* newblock)
{
    this->blocks.append(newblock);
    this->addItem(newblock);
}

bool Map::checkSideCollision()
{
    double blockLeft,blockRight;
    double blockTop,blockBot;

    double playerLeft,playerRight;
    double playerTop,playerBot;

    if(player->xspd<0)
    {
        // moving left

        for(int i=0;i<abs(player->xspd);i++)
        {
            // move xspd amount until player hits the block

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
                }
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
                }
            }

            player->setPos(player->x()+1,player->y());
        }
    }

    return false;
}

bool Map::checkVertCollision()
{
    double blockLeft,blockRight;
    double blockTop,blockBot;

    double playerLeft,playerRight;
    double playerTop,playerBot;

    if(player->yspd>0)
    {
        // moving down

        for(int i=0;i<player->yspd;i++)
        {
            // move yspd amount until player hits the ground

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
                }
            }

            player->setPos(player->x(),player->y()+1);
        }
    }

    else if(player->yspd<0)
    {
        // moving up

        for(int i=0;i<abs(player->yspd);i++)
        {
            // move yspd amount until player hits the ground

            playerLeft=player->x();
            playerRight=player->x()+player->w;
            playerTop=player->y();

            for(int i=0;i<blocks.size();i++)
            {
                // check if player is on a block

                blockLeft=blocks.at(i)->x;
                blockRight=blocks.at(i)->x+blocks.at(i)->w;
                blockBot=blocks.at(i)->y+blocks.at(i)->h;

                if(!(playerLeft>=blockRight || playerRight<=blockLeft))
                {
                    if(int(blockBot)==int(playerTop))
                    {
                        // player is under the ceiling
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
                }
            }

            player->setPos(player->x(),player->y()-1);
        }
    }

    return false;
}

void Map::mousePressEvent(QMouseEvent *mouse)
{
    if(mouse->button()==Qt::LeftButton)
    {
        player->yspd=-20;
    }
}

void Map::keyPressEvent(QKeyEvent* e)
{
    if(e->key()==Qt::Key_W)
    {
        player->yspd=-20;
    }
    if(e->key()==Qt::Key_A)
    {
        player->xspd=-5;
    }
    if(e->key()==Qt::Key_D)
    {
        player->xspd=5;
    }
    if(e->key()==Qt::Key_S)
    {
        player->xspd=0;
    }
}

int sign(int x)
{
    if(x>0)
    {
        return 1;
    }
    else if(x<0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
