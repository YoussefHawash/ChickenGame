#include <QApplication>
#include <QBrush>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "player.h"
#include "hud.h"
#include <QtMultimedia/QMediaPlayer>
#include<QAudioOutput>

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



    HUD::scoreText->setDefaultTextColor(Qt::blue);
    HUD::scoreText->setFont(QFont("serif", 20));
    HUD::scoreText->setPlainText("score: " + QString::number(0));
    HUD::scoreText->setPos(10, 45);
    HUD::healthText->setDefaultTextColor(Qt::red);
    HUD::healthText->setFont(QFont("serif", 20));
    HUD::healthText->setPlainText("Health: " + QString::number(3));
    HUD::healthText->setPos(10, 20);
    scene->addItem(HUD::healthText);
    scene->addItem(HUD::scoreText);

    QAudioOutput* audioOutput = new QAudioOutput();
    QMediaPlayer* soundEffect = new QMediaPlayer();
    soundEffect->setSource(QUrl(":/resources/sounds/7aga.mp3"));
    soundEffect->setAudioOutput(audioOutput);
    audioOutput->setVolume(50);
    soundEffect->setLoops(1000);
    soundEffect->play();



    view->show();




    return a.exec();
}
