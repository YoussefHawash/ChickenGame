#include "hud.h"
#include <QtMultimedia/QMediaPlayer>
#include <QTimer>
#include <QMessageBox>
#include <QAudioOutput>
#include "player.h"
#include<QGraphicsScene>

int HUD::score = 0;
int HUD::health = 3;
QGraphicsTextItem *HUD::healthText = new QGraphicsTextItem;
QGraphicsTextItem *HUD::scoreText = new QGraphicsTextItem;


void HUD::increase()
{
    HUD::score+=100;
    scoreText->setPlainText("Score: " + QString::number(score));

}

void HUD::decrease()
{
    health--;
     healthText->setPlainText("Health: " + QString::number(health));
    if(health<=0)
     {

         QGraphicsScene *temp= healthText->scene();
            Player::timer->stop();


               QMediaPlayer *sound = new QMediaPlayer();
             QAudioOutput *audioOutput = new QAudioOutput();
             sound->setSource(QUrl("qrc:/resources/sounds/game-over-arcade-6435.mp3"));
             sound->setAudioOutput(audioOutput);
             audioOutput->setVolume(50);
             sound->play();

             temp->clear();


             QGraphicsTextItem* gameOverText = new QGraphicsTextItem();
             gameOverText->setDefaultTextColor(Qt::red);
             gameOverText->setFont(QFont("serif", 48));
             gameOverText->setPlainText("GAME OVER!");
             gameOverText->setPos(temp->width() / 2 - 180, temp->height() / 2 - 48);
             temp->addItem(gameOverText);
             QMessageBox* msg = new QMessageBox();
             msg->setWindowTitle(QString("You Lost"));
             msg->setStyleSheet("QLabel{min-width: 500px;min-height: 100px;font-size: 40px}");
             msg->setText(QString("GAME OVER. Your score: ") + QString::number(score));
             msg->exec();



     }
}

