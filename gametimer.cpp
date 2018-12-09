#include "gameTimer.h"

GameTimer::GameTimer()
{
    this->start(1000/FPS);
}

GameTimer::GameTimer(int time)
{
    this->start(time);
    this->setSingleShot(true);
}


