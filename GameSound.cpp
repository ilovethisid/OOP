#include "GameSound.h"

GameSound::GameSound(Window* win,Map* map)
{
    this->bow_pull=new QMediaPlayer();
    this->bow_release=new QMediaPlayer();
    this->button=new QMediaPlayer();
    this->drop=new QMediaPlayer();

    bow_pull->setMedia(QUrl("qrc:/sounds/bow-pull.wav"));
    bow_release->setMedia(QUrl("qrc:/sounds/bow-release.mp3"));
    bow_release->setMedia(QUrl("qrc:/sounds/button.wav"));
    drop->setMedia(QUrl("qrc:/sounds/drop.wav"));

    connect(win,&Window::sound_bow_pull,bow_pull,&QMediaPlayer::play);
    connect(win,&Window::sound_bow_release,bow_release,&QMediaPlayer::play);
    connect(win,&Window::sound_button,button,&QMediaPlayer::play);
    connect(map,&Map::sound_button,button,&QMediaPlayer::play);
    connect(map,&Map::sound_drop,drop,&QMediaPlayer::play);
}

void GameSound::playbgm()
{
    // bgm
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/bgm.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    bgm = new QMediaPlayer();
    bgm->setVolume(30);
    bgm->setPlaylist(playlist);
    bgm->play();
    // background music
}
