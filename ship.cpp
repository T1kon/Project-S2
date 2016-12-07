#include "ship.h"
#include <QDebug>
#include <cmath>

Ship::Ship()
{
    setPixmap(QPixmap(":/images/ship.png"));
    setRotation(0);
    setX(100);
    setY(100);
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
    if (abs(acceleration) < MAX_ACCELERATION){
        acceleration += dir*0.1;
    }
    qDebug() << "accel:" << acceleration;
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

//void Ship::slow()
//{
//    double radian = (90 - this->rotation())/180*M_PI;
//    speedX = speedX - acceleration*cos(radian);
//    if (abs(speedX) > MAX_BACK_SPEED){
//        (speedX < 0)? speedX=-MAX_BACK_SPEED : speedX=MAX_BACK_SPEED;
//    }
//    speedY = speedY + acceleration*sin(radian);
//    if (abs(speedY) > MAX_BACK_SPEED){
//        (speedY < 0)? speedY=-MAX_BACK_SPEED : speedY=MAX_BACK_SPEED;
//    }
//    qDebug() << "speed decreased\n";
//}

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
    }
    if (canMoveB){
        addAcceleration(-1);
    }
    if (CanRotateL){
        rotateLeft();
    }
    if (CanRotateR){
        rotateRight();
    }

    accelerate();
    this->setPos(this->x() + speedX, this->y() + speedY);
}
