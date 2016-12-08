#include "meteor.h"
#include <QDebug>
Meteor::Meteor(int x, int y, int healthPoint)
{
    setPixmap(QPixmap(":/images/asteroid.png"));
    setPos(x,y);
    this->healthPoint = healthPoint;
}

