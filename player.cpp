#include "player.h"
#include <QAudioOutput>
#include <QDebug>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QtMultimedia/QMediaPlayer>
#include "bullet.h"
#include "enemy.h"
#include <QTimer>
#include <QMessageBox>

QTimer *Player::timer=new QTimer;

Player::Player(QGraphicsScene *scene)
{

    // *******  Create the Enemies automatically ********

    QObject::connect(timer, SIGNAL(timeout()),this,SLOT(createEnemy()));
    timer->start(2000);
}



void Player::keyPressEvent(QKeyEvent *event)
{
    // *******  Event Handling for the Player ********
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0) // to prevent the player from getting out of the screen
            setPos(x()-10,y());

    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+70<800)
            // to prevent the player from getting out of the screen
            setPos(x()+10,y());
    }
    else if(event->key()== Qt::Key_Down)

    { if(y()+70<600)
            // to prevent the player from getting out of the screen
            setPos(x(),y()+10);
    }
    else if(event->key()== Qt::Key_Up)

    { if(y()>0)
            // to prevent the player from getting out of the screen
            setPos(x(),y()-10);
    }

    else if (event->key() == Qt::Key_Space) {
        Bullet* bullet = new Bullet;
        bullet->setPos(x()+17, y());
        scene()->addItem(bullet);
    }
}

// CreateEnemy function used to create the eneimes
void Player::createEnemy()
{
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}
