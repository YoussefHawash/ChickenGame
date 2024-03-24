#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include "bullet.h"
#include "enemy.h"
Player::Player(QGraphicsScene *scene) {

    score_text->setDefaultTextColor(Qt::blue);
    score_text->setFont(QFont("serif", 20));
    score_text->setPlainText("score: " + QString::number(0));
    score_text->setPos(10,45);
    health_text->setDefaultTextColor(Qt::red);
    health_text->setFont(QFont("serif", 20));
    health_text->setPlainText("Health: " + QString::number(3));
    health_text->setPos(10,20);
    scene->addItem(health_text);
    scene->addItem(score_text);
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
    else if(event->key()== Qt::Key_Right)

    { if(x()+70<800)
            // to prevent the player from getting out of the screen
            setPos(x()+10,y());
    }
    else if(event->key()== Qt::Key_Space)
    {
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

int Player::score=0;
int Player::health=3;

QGraphicsTextItem* Player::score_text = new QGraphicsTextItem;
QGraphicsTextItem* Player::health_text= new QGraphicsTextItem;




