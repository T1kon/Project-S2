#include "shipai.h"
#include "shipplayer.h"
#include <QDebug>

ShipAI::ShipAI(double x, double y, double angle): Ship(x,y,angle)
{
    health = 1;
    targetX = 0;
    targetY = 0;
    targetAngle = 0;
    logicTimer = new QTimer();
    connect(logicTimer, SIGNAL(timeout()), this, SLOT(refreshLogics()));
    logicTimer->start(10);
}

ShipAI::~ShipAI()
{
}

double ShipAI::countAngle(double x, double y)
{
    return 180 - atan2(y, x) * 180 / M_PI;
}

double ShipAI::currentAngle(double angle)
{
    angle = fmod(angle, 360);
    if (angle < 0){
        angle += 360;
    }
    else if (angle >= 360){
        angle -= 360;
    }
    return angle;
}

int ShipAI::type() const
{
    return Type;
}

bool ShipAI::checkShootingDistance(double x, double y)
{
    if (sqrt((x*x + y*y)) < 1000){
        return true;
    }
    else{
        return false;
    }
}

void ShipAI::refreshLogics()
{
    foreach (QGraphicsItem * item, scene()->items()) {
        if(item->type() == ShipPlayer::Type){
            targetX = item->x();
            targetY = item->y();
            targetAngle = countAngle(targetY - y(), targetX - x());
            //qDebug() << targetX << targetY << targetAngle << currentAngle(rotation());
        }
    }
    CanShoot = false;
    if (targetAngle - currentAngle(rotation()) > 0 && targetAngle - currentAngle(rotation()) <= 180){
        CanRotateL = false;
        CanRotateR = true;
        if (targetAngle - currentAngle(rotation()) > 0 && targetAngle - currentAngle(rotation()) <= 10){
            CanShoot = checkShootingDistance(targetX - x(), targetY - y());
        }
    }
    else if (targetAngle == currentAngle(rotation())){
        CanRotateL = false;
        CanRotateR = false;
        CanShoot = checkShootingDistance(targetX - x(), targetY - y());
    }
    else{
        CanRotateL = true;
        CanRotateR = false;
    }
    canMoveF = true;
}
