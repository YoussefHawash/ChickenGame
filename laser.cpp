#include "laser.h"
#include <QGraphicsScene>
#include<QGraphicsPixmapItem>
#include <QTimer>
#include <QList>
Laser::Laser(): QObject(), QGraphicsPixmapItem()
{
    QPixmap laserimg("C:\\Users\\youse\\Desktop\\Spring 24\\Cs 2 Lab\\ChickenGame\\images\\laser.png");
    setPos(x()+70,y());
    laserimg=laserimg.scaled(70,70);
    setPixmap(laserimg);
    // *******  Generating the Bullets automatically ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
}
void Laser::move()
{

    // QList<QGraphicsItem *>colliding_items =collidingItems();
    // for(int i=0,n=colliding_items.size();i<n;++i)
    // {
    //     if(typeid(*(colliding_items[i]))== typeid(Enemy))
    //     {
    //         scene()->removeItem(colliding_items[i]);
    //         scene()->removeItem(this);
    //         delete colliding_items[i];
    //         delete this;
    //         return;
    //     }
    // }

    // *******  Moving the bullets upward ********
    setPos(x(),y()-10);
    if(pos().y()+30<0)
     {
         scene()->removeItem(this);
         delete this;
     }
}
