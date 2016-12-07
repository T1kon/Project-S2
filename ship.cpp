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
    health = MAX_HEALTH;
    CanRotateL = true;
    CanRotateR = true;
    canMoveB = true;
    canMoveF = true;

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(1000/60);

}

void Ship::accelerate()
{
    double radian = (90 - this->rotation())/180*M_PI;
    speedX = speedX + ACCELERATION*cos(radian);
    if (abs(speedX) > MAX_SPEED){
        (speedX < 0)? speedX=-MAX_SPEED : speedX=MAX_SPEED;
    }
    speedY = speedY - ACCELERATION*sin(radian);
    if (abs(speedY) > MAX_SPEED){
        (speedY < 0)? speedY=-MAX_SPEED : speedY=MAX_SPEED;
    }
    qDebug() << "speed increased\n";
}

void Ship::slow()
{
    double radian = (90 - this->rotation())/180*M_PI;
    speedX = speedX - ACCELERATION*cos(radian);
    if (abs(speedX) > MAX_BACK_SPEED){
        (speedX < 0)? speedX=-MAX_BACK_SPEED : speedX=MAX_BACK_SPEED;
    }
    speedY = speedY + ACCELERATION*sin(radian);
    if (abs(speedY) > MAX_BACK_SPEED){
        (speedY < 0)? speedY=-MAX_BACK_SPEED : speedY=MAX_BACK_SPEED;
    }
    qDebug() << "speed decreased\n";
}

void Ship::rotate_left()
{
    this->setRotation(this->rotation() - ROTATION_SPEED);
    qDebug() << "rotated left\n" << rotation()
             <<" sin(" << sin(rotation()*M_PI/180) << ")";
}

void Ship::rotate_right()
{
    this->setRotation(this->rotation() + ROTATION_SPEED);
    qDebug() << "rotated right\n" << rotation()
                <<" sin(" << sin(rotation()*M_PI/180) << ")";
}


void Ship::move()
{
    if (canMoveF){
        accelerate();
    }
    if (canMoveB){
        slow();
    }
    if (CanRotateL){
        rotate_left();
    }
    if (CanRotateR){
        rotate_right();
    }
    this->setPos(this->x() + speedX, this->y() + speedY);
}
