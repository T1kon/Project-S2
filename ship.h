#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include "bullet.h"

class Ship: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    double speedX, speedY;
    unsigned int health;
    double acceleration;
    const double MAX_SPEED = 4.0;
    const double ROTATION_SPEED = 1.5;
    const int MAX_HEALTH = 10;
    QTimer * timer;
    QTimer * shootTimer;
protected:
    bool canMoveF, canMoveB, CanRotateL, CanRotateR, CanShoot;
public:
    Ship();
    Ship(double X, double Y, double angle);
    void setShip();
public slots:
    void addAcceleration(double dir);
    void accelerate();
    void slow();
    void rotateLeft();
    void rotateRight();
    void move();
    void fire();
    void reduseHP();
    unsigned int getHP() const;
};

#endif // SHIP_H
