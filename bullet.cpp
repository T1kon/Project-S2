#include "bullet.h"

Bullet::Bullet(double x, double y, double angle)
{
    setPos(x, y);
    setPixmap(QPixmap(":/images/bullet.png"));
    setOffset(-2.5, -10);
    setRotation(angle);

    QTimer * moveTimer = new QTimer();
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(moveBullet()));
    moveTimer->start(100/6);

    lifeTime = new QTimer();
    connect(lifeTime, SIGNAL(timeout()), this, SLOT(deleteBullet()));
    lifeTime->start(1000);
}

void Bullet::moveBullet()
{
    double angle = (90 - this->rotation())/180*M_PI;
    setPos(x() + SPEED*cos(angle), y() - SPEED*sin(angle));
}

void Bullet::deleteBullet()
{
    delete this;
}
