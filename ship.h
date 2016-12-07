#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsRectItem>
#include <QObject>

class Ship: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    double speedX, speedY;
    unsigned int health;
    const double ACCELERATION = 1.0;
    const double MAX_SPEED = 10.0;
    const double MAX_BACK_SPEED = MAX_SPEED / 5.0;
    const double ROTATION_SPEED = 5;
    const int MAX_HEALTH = 10;
public:
    Ship();
public slots:
    void accelerate();
    void slow();
    void rotate_left();
    void rotate_right();
    void move();
};

#endif // SHIP_H
