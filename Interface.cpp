#include "Interface.h"

#include <QColor>
#include <QBrush>
#include <QDebug>
#include <QMediaPlayer>

StartMenu::StartMenu(int WINWIDTH,int WINHEIGHT)
{
    // scene
    this->setBackgroundBrush(Qt::black);
    this->setSceneRect(0,0,WINWIDTH,WINHEIGHT);

    // text
    text=new QGraphicsTextItem("S h i n e !");
    text->setFont(QFont("Century Gothic",48));
    text->setDefaultTextColor(Qt::white);
    int textWidth=int(text->boundingRect().width());
    int textHeight=int(text->boundingRect().height());
    addItem(text);
    text->setPos(WINWIDTH/2-textWidth/2,WINHEIGHT/2-textHeight/2-100);
    text->hide();

    // player-like rect
    QGraphicsRectItem* rect=new QGraphicsRectItem();
    rect->setRect(WINWIDTH/2-15,WINHEIGHT/2-15,30,30);
    rect->setPen(QPen(Qt::white,2));
    addItem(rect);

    // button
    int buttonWidth=250;
    int buttonHeight=50;
    button=new QPushButton("Start");
    button->setFont(QFont("Century Gothic",28));
    button->setGeometry(QRect(WINWIDTH/2-buttonWidth/2,WINHEIGHT/2+100,buttonWidth,buttonHeight));
    button->setAutoFillBackground(false);
    button->setStyleSheet("color:white;background-color:black;");
    button->hide();
    button->setMouseTracking(true);
    addWidget(button);

    displayText();
    displayButton();
}

void StartMenu::displayText()
{
    QMediaPlayer* mediaPlayer=new QMediaPlayer();
    mediaPlayer->setMedia(QUrl("qrc:/sounds/button.wav"));
    mediaPlayer->play();
    // play button sound;
    text->show();
}

void StartMenu::displayButton()
{
    QMediaPlayer* mediaPlayer=new QMediaPlayer();
    mediaPlayer->setMedia(QUrl("qrc:/sounds/button.wav"));
    mediaPlayer->play();
    // play button sound;
    button->show();
}

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
    QMediaPlayer* mediaPlayer=new QMediaPlayer();
    mediaPlayer->setMedia(QUrl("qrc:/sounds/button.wav"));
    mediaPlayer->play();
    // play button sound;
    text->show();
}

void EndingScene::displayButton()
{
    QMediaPlayer* mediaPlayer=new QMediaPlayer();
    mediaPlayer->setMedia(QUrl("qrc:/sounds/button.wav"));
    mediaPlayer->play();
    // play button sound;
    button->show();
}





