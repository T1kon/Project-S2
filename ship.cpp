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
    setOffset(-12,-25);
    speedX = 0;
    speedY = 0;
    acceleration = 0.0;
    health = MAX_HEALTH;
    CanRotateL = false;
    CanRotateR = false;
    canMoveB = false;
    canMoveF = false;
    CanShoot = false;

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(1000/60);

    shootTimer = new QTimer();
    connect(shootTimer, SIGNAL(timeout()), this, SLOT(fire()));
    shootTimer->start(0);
}

void Ship::deleteShip()
{

    Explosion * exp = new Explosion(this->x(), this->y());
    scene()->addItem(exp);
    scene()->removeItem(this);
    delete timer;
    delete shootTimer;
    delete this;
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
    if (abs(speedX) > MAX_SPEED/4){
        (speedX < 0)? speedX=-MAX_SPEED/2 : speedX=MAX_SPEED/2;
    }

    speedY -= acceleration*sin(radian);
    if (abs(speedY) > MAX_SPEED/4){
        (speedY < 0)? speedY=-MAX_SPEED/2 : speedY=MAX_SPEED/2;
    }

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
    if (this->getHP() > 0){
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
        checkCollision();
        //qDebug() << "| Coords:" << x() << " " << y() << fmod(rotation(), 360);
        this->setPos(this->x() + speedX, this->y() + speedY);
   }
}

void Ship::fire()
{
    shootTimer->start(0);
    if (CanShoot){
        double radian = (90 - this->rotation())/180*M_PI;
        Bullet * bullet = new Bullet(x() + 50*cos(radian), y() - 50*sin(radian), rotation());
        scene()->addItem(bullet);
        shootTimer->start(1000/2);
    }
}

void Ship::reduceHP()
{
    this->health --;
    if (this->health <= 0){
        deleteShip();
    }
}

void Ship::checkCollision()
{
    foreach (QGraphicsItem * item, collidingItems()) {
        if(item->type() == Meteor::Type){
            dynamic_cast<Meteor*>(item)->reduceHP();
            this->reduceHP();
            return;
        }
    }
}

unsigned int Ship::getHP() const
{
    return this->health;
}
