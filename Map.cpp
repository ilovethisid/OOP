#include "Map.h"

#include <QDebug>
#include <math.h>
#include <ctime>
#include <cstdlib>

using namespace std;

Map::Map(GameTimer* timer)
{
    this->player=new Player(MAPWIDTH/2,MAPHEIGHT-100);
    this->addItem(player);

    this->timer=timer;
    connect(this->timer,&QTimer::timeout,this,&Map::update);

    blockInit(); // create all block

    this->gameoverLayer=new GameoverLayer();
    this->gameoverLayer->setRect(0,0,MAPWIDTH,MAPHEIGHT);
    this->gameoverLayer->hide();
    this->addItem(gameoverLayer);
    this->gameover=false;
    // init gameover layer

    //this->addItem(gameoverLayer->text);
    //gameoverLayer->text->hide();
}

void Map::update()
{
    // player move
    if(player->isAlive)
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
                    if(player->yspd>player->deathspd)
                    {
                        // if player falls too fast
                        player->die();
                        gameoverLayer->show();
                        this->gameover=true;
                    }
                    else
                    {
                        player->yspd=int(-0.5*player->yspd);
                        // bounce
                    }
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

void Map::keyPressEvent(QKeyEvent* e)
{
    if(e->key()==Qt::Key_W)
    {
        player->yspd=-10;
    }
    if(e->key()==Qt::Key_A)
    {
        player->xspd=-10;
    }
    if(e->key()==Qt::Key_D)
    {
        player->xspd=10;
    }
    if(e->key()==Qt::Key_S)
    {
        player->xspd=0;
        player->yspd=0;
    }
}

void Map::blockInit()
{
    Block* ground=new Block(0,MAPHEIGHT-10,MAPWIDTH,MAPHEIGHT); // ground
    Block* leftwall=new Block(0,0,10,MAPHEIGHT); // left wall
    Block* rightwall=new Block(MAPWIDTH-10,0,MAPWIDTH,MAPHEIGHT); // right wall

    int blockX=MAPWIDTH/2;
    int blockY=MAPHEIGHT;
    int dir=1;

    // making random blocks that go up
    for(int i=0;i<50;i++)
    {
        srand(unsigned(int(time(nullptr))+i));
        // new seed for rand()

        if(rand()%2==0)
        {
            dir=1;
        }
        else
        {
            dir=-1;
        }

        blockX+=dir*200;

        switch(rand()%4)
        {
        case 0:
        {
            blockX+=dir*60;
            blockY-=150;
            break;
        }
        case 1:
        {
            blockX+=dir*100;
            blockY-=100;
            break;
        }
        default:
        {
            blockX+=dir*150;
            blockY-=60;
        }
        }

        Block* newblock=new Block(blockX,blockY,200,20);
        this->addBlock(newblock);
    }

    if(rand()%2==0)
    {
        dir=1;
    }
    else
    {
        dir=-1;
    }

    blockX+=dir*200;
    blockX+=dir*60;
    blockY-=150;

    Block* endblock=new Block(blockX,blockY,200,20);
    this->addBlock(endblock);
    endblock->setBrush(Qt::green);

    // add the item to the map
    this->addBlock(ground);
    this->addBlock(leftwall);
    this->addBlock(rightwall);
}



