#include "gameTimer.h"

GameTimer::GameTimer()
{

}

GameTimer::GameTimer(int time)
{
    this->start(time);
    this->setSingleShot(true);
}

void GameTimer::startTimer()
{
    this->start(1000/FPS);
}


