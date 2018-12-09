#include "Map.h"

#include <QDebug>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <QMediaPlayer>
#include <QLinearGradient>

using namespace std;

Map::Map(GameTimer* timer)
{
    this->player=new Player(PLAYER_START_X,PLAYER_START_Y);
    this->addItem(player);

    this->timer=timer;
    connect(this->timer,&QTimer::timeout,this,&Map::update);

    blockInit(); // create all block

    QGradient* gradient=new QLinearGradient(MAPWIDTH/2,0,MAPWIDTH/2,MAPHEIGHT);
    gradient->setColorAt(1,Qt::white);
    gradient->setColorAt(0.75,QColor(153,153,255));
    gradient->setColorAt(0.5,QColor(255,0,0));
    gradient->setColorAt(0.25,Qt::black);
    gradient->setColorAt(0,Qt::black);
    QBrush* bgBrush=new QBrush(QGradient(*gradient));
    setBackgroundBrush(QBrush(*bgBrush));

    this->gameoverLayer=new GameoverLayer();
    this->gameoverLayer->hide();
    this->addItem(gameoverLayer);
    // init gameover layer

    this->addWidget(gameoverLayer->button);
    connect(gameoverLayer->button,&QPushButton::pressed,this,&Map::respawn);
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

void Map::respawn()
{
    player->respawn();
    player->setPos(PLAYER_START_X,PLAYER_START_Y);
    this->gameoverLayer->button->hide();
    this->gameoverLayer->hide();
    this->timer->start();
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

                if(abs(player->xspd)>0)
                {
                    QMediaPlayer* mediaPlayer=new QMediaPlayer();
                    mediaPlayer->setMedia(QUrl("qrc:/sounds/drop.wav"));
                    mediaPlayer->setVolume(100);
                    mediaPlayer->play();
                }
                // play sound

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

                if(abs(player->xspd)>0)
                {
                    QMediaPlayer* mediaPlayer=new QMediaPlayer();
                    mediaPlayer->setMedia(QUrl("qrc:/sounds/drop.wav"));
                    mediaPlayer->setVolume(100);
                    mediaPlayer->play();
                }
                // play sound

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
                        emit gameover();
                        this->timer->stop();
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

                if(abs(player->yspd)>0)
                {
                    QMediaPlayer* mediaPlayer=new QMediaPlayer();
                    mediaPlayer->setMedia(QUrl("qrc:/sounds/drop.wav"));
                    mediaPlayer->setVolume(100);
                    mediaPlayer->play();
                }
                // play sound

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

                if(abs(player->yspd)>0)
                {
                    QMediaPlayer* mediaPlayer=new QMediaPlayer();
                    mediaPlayer->setMedia(QUrl("qrc:/sounds/drop.wav"));
                    mediaPlayer->setVolume(100);
                    mediaPlayer->play();
                }
                // play sound

                return true;
            }

            player->setPos(player->x(),player->y()-1);
        }
    }
    else
    {
        // if player->yspd=0

        int jumpheight=player->maxspd*(player->maxspd-1)/2;

        if(player->y()<endblock->y-jumpheight+30)
        {
            // if player is higher than endblock
            timer->stop();
            emit gameend();
        }
    }

    return false;
}

void Map::keyPressEvent(QKeyEvent* e)
{
    if(e->key()==Qt::Key_W)
    {
        player->yspd=-20;
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
    if(blocks.size()>0)
    {
        for(int i=0;i<blocks.size();i++)
        {
            this->removeItem(blocks.at(i));
        }
        blocks.clear();
    }

    Block* ground=new Block(0,MAPHEIGHT-10,MAPWIDTH,MAPHEIGHT); // ground
    Block* leftwall=new Block(0,0,10,MAPHEIGHT); // left wall
    Block* rightwall=new Block(MAPWIDTH-10,0,MAPWIDTH,MAPHEIGHT); // right wall

    // add the item to the map
    this->addBlock(ground);
    this->addBlock(leftwall);
    this->addBlock(rightwall);

    // variables to create random blocks
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
        if(newblock->y<MAPHEIGHT/2)
        {
            newblock->setPen(QPen(Qt::white,2));
        }
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

    endblock=new Block(blockX,blockY,200,20);
    endblock->setBrush(Qt::green);
    endblock->setPen(QPen(Qt::white,2));
    this->addBlock(endblock);
}



