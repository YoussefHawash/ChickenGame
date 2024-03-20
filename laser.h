#ifndef LASER_H
#define LASER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsPixmapItem>

class Laser:public QObject,public QGraphicsPixmapItem
{
public:
    Laser();
};

#endif // LASER_H
