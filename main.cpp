#include <QApplication>
#include <QBrush>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "player.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    // ******* Create the Scene ********
    QGraphicsScene *scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, 800, 600);
    // *******  Create the View ********
    QGraphicsView *view = new QGraphicsView(scene);
    view->setFixedSize(800, 600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // *******  Create the Player ********
    Player *ship = new Player(scene);
    ship->setPixmap(QPixmap(":/resources/images/ship.png").scaled(70, 70));
    scene->addItem(ship);
    // *******  Setting the foucs to the Player ********
    ship->setFlag(QGraphicsItem::ItemIsFocusable);
    ship->setFocus();
    // *******  Adjust the location of the Player (middle of the screen) ********
    ship->setPos(view->width() / 2, view->height() - ship->pixmap().height());

    QPixmap back(":/resources/images/background.jpeg");
    scene->setBackgroundBrush(back.scaled(scene->width(),
                                          scene->height(),
                                          Qt::IgnoreAspectRatio,
                                          Qt::SmoothTransformation));

    view->show();
    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),ship,SLOT(createEnemy()));
    time->start(2000);



    return a.exec();
}
