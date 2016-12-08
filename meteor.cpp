#include "meteor.h"
#include <QDebug>
Meteor::Meteor(double x, double y, int healthPoint)
{
    setPixmap(QPixmap(":/images/meteor.png"));
    setOffset(-20.5, -20.5);
    setPos(x,y);
    this->healthPoint = healthPoint;
}

