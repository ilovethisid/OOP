#pragma once

#include <QTimer>

#define FPS 45

class GameTimer:public QTimer
{
public:
    GameTimer();
    GameTimer(int time);

    void startTimer();
};
