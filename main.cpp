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
    // ******* Create the Scene ********
    QGraphicsScene scene;
    scene.setSceneRect(0,0,800,600);
    // *******  Create the View ********
    QGraphicsView view;
    view.setFixedSize(800,600);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // *******  Create the Player ********
    QPixmap plyrimg(":/soora/images/ship.png");
    Player *ship=new Player(&scene);
    plyrimg=plyrimg.scaled(70,70);
    ship->setPixmap(plyrimg);
    scene.addItem(ship);

    // *******  Setting the foucs to the Player ********
    ship->setFlag(QGraphicsItem::ItemIsFocusable);
    ship->setFocus();
    // *******  Adjust the location of the Player (middle of the screen) ********
    ship->setPos(view.width() / 2, view.height() - plyrimg.height());


    QPixmap back(":/soora/images/background.jpeg");
    scene.setBackgroundBrush(back.scaled(scene.width(),scene.height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));


    // *******   Assign scene to the view   ***************
    view.setScene(&scene);
    view.show();

    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),ship,SLOT(createEnemy()));
    time->start(2000);



    return a.exec();
}
