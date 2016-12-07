#include "ship.h"
#include <QDebug>

Ship::Ship()
{
    setRect(0,0,10,50);
    setRotation(0);
    speedX = 0;
    speedY = 0;
    health = MAX_HEALTH;
}

void Ship::accelerate()
{
    speedX = speedX + ACCELERATION*sin(this->rotation());
    if (abs(speedX) > MAX_SPEED){
        (speedX < 0)? speedX=-MAX_SPEED : speedX=MAX_SPEED;
    }
    speedY = speedY - ACCELERATION*cos(this->rotation());
    if (abs(speedY) > MAX_SPEED){
        (speedY < 0)? speedY=-MAX_SPEED : speedY=MAX_SPEED;
    }
    qDebug() << "speed increased\n";
}

void Ship::slow()
{
    speedX = speedX - ACCELERATION*sin(this->rotation());
    if (abs(speedX) > MAX_BACK_SPEED){
        (speedX < 0)? speedX=-MAX_BACK_SPEED : speedX=MAX_BACK_SPEED;
    }
    speedY = speedY + ACCELERATION*cos(this->rotation());
    if (abs(speedY) > MAX_BACK_SPEED){
        (speedY < 0)? speedY=-MAX_BACK_SPEED : speedY=MAX_BACK_SPEED;
    }
    qDebug() << "speed decreased\n";
}

void Ship::rotate_left()
{
    this->setRotation(this->rotation() - ROTATION_SPEED);
    qDebug() << "rotated left\n";
}

void Ship::rotate_right()
{
    this->setRotation(this->rotation() - ROTATION_SPEED);
    qDebug() << "rotated right\n";
}


void Ship::move()
{
    this->setPos(this->x() + speedX, this->y() + speedY);
}
