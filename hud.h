#ifndef HUD_H
#define HUD_H
#include<QGraphicsPixmapItem>
#include<QGraphicsTextItem>

class HUD
{

public:

    static void setHealthText(QGraphicsTextItem* healthText);
    static void setScoreText(QGraphicsTextItem* scoreText);
    static void increase();
    static void decrease();
    static int health;
    static int score;
    static QGraphicsTextItem* healthText;
    static QGraphicsTextItem* scoreText;
public:
    HUD();
};

#endif // HUD_H
