#include "bullet.h"
#include <QGraphicsScene>
#include "meteor.h"
#include "shipai.h"

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
    lifeTime->start(3000);
}

void Bullet::moveBullet()
{
    foreach (QGraphicsItem * item, collidingItems()) {
        if(item->type() == Meteor::Type || item->type() == ShipAI::Type){
            scene()->removeItem(item);           
            delete item;
            deleteBullet();
            return;
        }

    }

    double angle = (90 - this->rotation())/180*M_PI;
    setPos(x() + SPEED*cos(angle), y() - SPEED*sin(angle));
}

void Bullet::deleteBullet()
{
    scene()->removeItem(this);
    delete this;
}
