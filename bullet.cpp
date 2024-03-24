#include "bullet.h"
#include "player.h"
#include <QGraphicsScene>
#include<QGraphicsPixmapItem>
#include <QTimer>
#include <QList>
#include "enemy.h"
Bullet::Bullet()  : QObject(), QGraphicsPixmapItem() {
    QPixmap bulletimg(":/soora/images/red_laser.png");
    bulletimg=bulletimg.scaled(40,40);
    setPixmap(bulletimg);
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
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            Player::score+=100;
            Player::score_text->setPlainText("score: " + QString::number(Player::score));
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
