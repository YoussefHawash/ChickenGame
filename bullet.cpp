#include "bullet.h"
#include <QAudioOutput>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QtMultimedia/QMediaPlayer>
#include "enemy.h"
#include "player.h"
#include "hud.h"

Bullet::Bullet()  : QObject(), QGraphicsPixmapItem() {
    QPixmap bulletimg(":/resources/images/red_laser.png");
    setPixmap(bulletimg.scaled(40, 40));
    QMediaPlayer *sound = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput();
    sound->setSource(QUrl("qrc:/resources/sounds/laser.mp3"));
    sound->setAudioOutput(audioOutput);
    audioOutput->setVolume(0.5);
    sound->play();
    // *******  Generating the Bullets automatically ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
}


void Bullet::move()
{

    QList<QGraphicsItem *>colliding_items =collidingItems();
    for(int i=0,n=colliding_items.size();i<n;++i)
    {
        if(typeid(*(colliding_items[i]))== typeid(Enemy))
        {
            QMediaPlayer *sound = new QMediaPlayer;
            QAudioOutput *audioOutput = new QAudioOutput();
            sound->setSource(QUrl("qrc:/resources/sounds/quack.m4a"));
            sound->setAudioOutput(audioOutput);
            audioOutput->setVolume(0.5);
            sound->play();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            HUD::increase();
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // *******  Moving the bullets upward ********
    setPos(x(),y()-10);
    if(pos().y()+30<0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
