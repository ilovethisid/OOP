#pragma once

#include "window.h"
#include "Map.h"

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QObject>

class GameSound:public QObject
{
    Q_OBJECT
public:
    QMediaPlayer* bgm;
    QMediaPlayer* bow_pull;
    QMediaPlayer* bow_release;
    QMediaPlayer* button;
    QMediaPlayer* drop;
    QMediaPlayer* splat;

    GameSound(Window* win,Map* map);

    void playbgm();
};

