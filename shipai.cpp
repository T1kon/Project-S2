#include "shipai.h"
#include "shipplayer.h"
#include <QDebug>

ShipAI::ShipAI(double x, double y, double angle): Ship(x,y,angle)
{
    if (counter.getCount() < MAX_COUNT){

    }
    else{
        delete this;
    }
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
    return atan2(y, x) * 180 / M_PI;
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

void ShipAI::refreshLogics()
{
    foreach (QGraphicsItem * item, scene()->items()) {
        if(item->type() == ShipPlayer::Type){
            targetX = item->x();
            targetY = item->y();
            targetAngle = countAngle(targetY - y(), targetX - x());
            qDebug() << targetX << targetY << targetAngle;
        }
    }
    if(targetAngle != currentAngle(rotation())){
        if (targetAngle > currentAngle(rotation())){
            CanRotateL = true;
            CanRotateR = false;
        }
        else if (targetAngle < currentAngle(rotation())){
            CanRotateL = false;
            CanRotateR = true;
        }
        else{
            CanRotateL = false;
            CanRotateR = false;
        }
    }
}

template<> int Counter<ShipAI>::count=0;
