#ifndef SHIP_H
#define SHIP_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Ship: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    double speedX, speedY;
    unsigned int health;
    double acceleration;
    const double MAX_ACCELERATION = 1.0;
    const double MAX_SPEED = 5.0;
    const double MAX_BACK_SPEED = MAX_SPEED / 5.0;
    const double ROTATION_SPEED = 5;
    const int MAX_HEALTH = 10;
    QTimer * timer;
protected:
    bool canMoveF, canMoveB, CanRotateL, CanRotateR;
public:
    Ship();
public slots:
    void addAcceleration(double dir);
    void accelerate();
   // void slow();
    void rotateLeft();
    void rotateRight();
    void move();
};

#endif // SHIP_H
