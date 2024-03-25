#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Player(QGraphicsScene *);
    void keyPressEvent(QKeyEvent * event);
    static int score;
    static int health;
    static QGraphicsTextItem *score_text;
    static QGraphicsTextItem* health_text;
    static void decreasehealth();
    static void increasescore();
public slots:
    void createEnemy();

};

#endif // PLAYER_H
