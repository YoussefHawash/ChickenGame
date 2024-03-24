#ifndef LASER_H
#define LASER_H


#include <QObject>
#include <QGraphicsPixmapItem>

class Laser: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Laser();
private slots:
    void move();
};

#endif // LASER_H
