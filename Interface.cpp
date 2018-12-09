#include "Interface.h"

#include <QColor>
#include <QBrush>
#include <QDebug>

RespawnButton::RespawnButton(QString str):QPushButton (str)
{

}

GameoverLayer::GameoverLayer()
{
    this->setBrush(QBrush(QColor(105,105,105,150),Qt::SolidPattern));

    text=new QGraphicsTextItem("You Died",this);
    text->setFont(QFont("Century Gothic",48));

    button=new RespawnButton("Respawn");
}

void GameoverLayer::display(int originX,int originY,int WINWIDTH,int WINHEIGHT)
{
    // layer
    setRect(originX,originY,WINWIDTH,WINHEIGHT);

    // text
    int textWidth=int(text->boundingRect().width());
    int textHeight=int(text->boundingRect().height());
    text->setPos(originX+WINWIDTH/2-textWidth/2,originY+WINHEIGHT/2-textHeight/2);

    // button
    int buttonWidth=250;
    int buttonHeight=50;
    button->setFont(QFont("Century Gothic",28));
    button->setGeometry(QRect(originX+WINWIDTH/2-buttonWidth/2,originY+WINHEIGHT/2+100,buttonWidth,buttonHeight));
    button->setStyleSheet("background-color:lightgray;");

    // display
    this->button->show();
    this->button->setFocus();
    this->show();
}


EndingScene::EndingScene(int WINWIDTH,int WINHEIGHT)
{
    // scene
    this->setBackgroundBrush(Qt::black);
    this->setSceneRect(0,0,WINWIDTH,WINHEIGHT);

    // text
    text=new QGraphicsTextItem("S h i n e !");
    text->setFont(QFont("Century Gothic",48));
    text->setDefaultTextColor(Qt::yellow);
    int textWidth=int(text->boundingRect().width());
    int textHeight=int(text->boundingRect().height());
    addItem(text);
    text->setPos(WINWIDTH/2-textWidth/2,WINHEIGHT/2-textHeight/2-100);
    text->hide();

    // button
    int buttonWidth=250;
    int buttonHeight=50;
    button=new QPushButton("Regame?");
    button->setFont(QFont("Century Gothic",28));
    button->setGeometry(QRect(WINWIDTH/2-buttonWidth/2,WINHEIGHT/2+100,buttonWidth,buttonHeight));
    button->setAutoFillBackground(false);
    button->setStyleSheet("color:yellow;background-color:black;");
    button->hide();
    button->setMouseTracking(true);
    addWidget(button);

    // timer
    timer=new GameTimer(1000);
    connect(timer,&QTimer::timeout,this,&EndingScene::displayText);
    timer=new GameTimer(2000);
    connect(timer,&QTimer::timeout,this,&EndingScene::displayButton);
}

void EndingScene::displayText()
{
    text->show();
}

void EndingScene::displayButton()
{
    button->show();
}





