#include "enemy.h"
#include "player.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QTimer>
#include <QDebug>


Enemy::Enemy() : QObject(),QGraphicsPixmapItem() {
    // *******  Setting the size of the enemy ********
    QPixmap chick(":/soora/images/chicken.png");
    chick=chick.scaled(70,70);
    this->setPixmap(chick);

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
    if(y()+pixmap().height()>scene()->height())
    {
        scene()->removeItem(this);
        Player::health--;
        Player::health_text->setPlainText("Health: " + QString::number(Player::health));
        delete this;
        return;
    }

    QList<QGraphicsItem *>colliding_items =collidingItems();
    for(int i=0,n=colliding_items.size();i<n;++i)
    {
        if(typeid(*(colliding_items[i]))== typeid(Player))
        {

            scene()->removeItem(this);
            Player::health--;
            Player::health_text->setPlainText("Health: " + QString::number(Player::health));
            delete this;
            return;

        }
    }
}
