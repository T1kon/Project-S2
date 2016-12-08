#include "ship.h"
#include <QDebug>
#include <cmath>

Ship::Ship()
{
    setRotation(0);
    setX(0);
    setY(0);
    setShip();
}

Ship::Ship(double X, double Y, double angle)
{
    setRotation(angle);
    setX(X);
    setY(Y);
    setShip();
}

void Ship::setShip()
{
    setPixmap(QPixmap(":/images/ship.png"));
    setOffset(-10,-25);
    speedX = 0;
    speedY = 0;
    acceleration = 0.0;
    health = MAX_HEALTH;
    CanRotateL = true;
    CanRotateR = true;
    canMoveB = true;
    canMoveF = true;

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(1000/60);
}

void Ship::addAcceleration(double dir)
{
    acceleration = dir*0.1;
}

void Ship::accelerate()
{
    double radian = (90 - this->rotation())/180*M_PI;
    speedX += acceleration*cos(radian);
    if (abs(speedX) > MAX_SPEED){
        (speedX < 0)? speedX=-MAX_SPEED : speedX=MAX_SPEED;
    }
    speedY -= acceleration*sin(radian);
    if (abs(speedY) > MAX_SPEED){
        (speedY < 0)? speedY=-MAX_SPEED : speedY=MAX_SPEED;
    }
}

void Ship::slow()
{
    double radian = (90 - this->rotation())/180*M_PI;
    speedX += acceleration*cos(radian);
    speedY -= acceleration*sin(radian);
    if (abs(speedX) < 0.1 && abs(speedY) < 0.1){
        speedX = 0;
        speedY = 0;
    }
    acceleration = 0;
}

void Ship::rotateLeft()
{
    this->setRotation(this->rotation() - ROTATION_SPEED);
}

void Ship::rotateRight()
{
    this->setRotation(this->rotation() + ROTATION_SPEED);
}


void Ship::move()
{
    if (canMoveF){
        addAcceleration(1);
        accelerate();
    }
    else if (canMoveB){
        addAcceleration(-1);
        slow();
    }
    else if (!canMoveF && !canMoveB){
        accelerate();
    }
    if (CanRotateL){
        rotateLeft();
    }
    if (CanRotateR){
        rotateRight();
    }
    qDebug() << "| Coords:" << x() << " " << y() << fmod(rotation(), 360);
    this->setPos(this->x() + speedX, this->y() + speedY);
}
