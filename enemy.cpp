#include "enemy.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QTimer>
#include <QDebug>

Enemy::Enemy() {
    // *******  Setting the size of the enemy ********
    setRect(0,0,100,100);

    // *******  Setting the postion of the enemy within the view dimensions ********
    int random_number = rand() % 700;
    // scene - hieght of bullet
    setPos(random_number,0);
    // *******  Moving the enemies downwards automatically every 50 milli second ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);

}
// Function move: move the enemy downwards untill the end of the scene then remove it and delete it
void Enemy::move()
{
    setPos(x(),y()+5);
    if(y()+rect().height()>scene()->height())
    {
        scene()->removeItem(this);
        delete this;
    }
}
