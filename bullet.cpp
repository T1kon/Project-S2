#include "bullet.h"
#include <QGraphicsScene>
#include "meteor.h"
#include "shipai.h"
#include "shipplayer.h"

Bullet::Bullet(double x, double y, double angle)
{
    setPos(x, y);
    setPixmap(QPixmap(":/images/bullet.png"));
    setOffset(-2.5, -10);
    setRotation(angle);

    moveTimer = new QTimer();
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(moveBullet()));
    moveTimer->start(100/6);

    lifeTime = new QTimer();
    connect(lifeTime, SIGNAL(timeout()), this, SLOT(deleteBullet()));
    lifeTime->start(3000);
}

void Bullet::moveBullet()
{
    foreach (QGraphicsItem * item, collidingItems()) {
        if(item->type() == Meteor::Type){
            dynamic_cast<Meteor*>(item)->reduceHP();
            deleteBullet();
            return;
        }
        else if(item->type() == ShipAI::Type || item->type() == ShipPlayer::Type){
            dynamic_cast<Ship*>(item)->reduceHP();
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
    delete lifeTime;
    delete moveTimer;
    delete this;
}
