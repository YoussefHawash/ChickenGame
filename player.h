#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>

#include<QTime>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT


public:
    Player(QGraphicsScene *);
    void keyPressEvent(QKeyEvent * event);
    static void Gameover();
    static QTimer *timer;
public slots:
    void createEnemy();

};

#endif // PLAYER_H
