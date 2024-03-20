

#include <QApplication>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include "player.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect(0,0,800,600);


    QGraphicsView view;
    view.setFixedSize(800,600);
    view.setScene(&scene);
    view.show();
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    QPixmap pixmap1(":/soora/ship.png");
    Player *ship=new Player;
    ship->setPixmap(pixmap1);
    ship->setPos(300,250);
    ship->setFlag(QGraphicsItem::ItemIsFocusable);
    ship->setFocus();


    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),rect,SLOT(createEnemy()));
    time->start(2000);



    return a.exec();
}
