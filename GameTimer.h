#pragma once

#include <QTimer>

#define FPS 30

class GameTimer:public QTimer
{
public:
    GameTimer();
    GameTimer(int time);
};
