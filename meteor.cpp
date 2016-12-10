#include "meteor.h"
#include <QDebug>
#include <QGraphicsScene>
Meteor::Meteor(double x, double y, int health)
{
    setPixmap(QPixmap(":/images/meteor.png"));
    setOffset(-20.5, -20.5);
    setPos(x,y);
    this->health = health;
}



int Meteor::type() const
{
    return Type;
}

void Meteor::reduceHP()
{
    if (this->health > 1){
        this->health--;
    }
    else{
        scene()->removeItem(this);
        delete this;
    }
}

unsigned int Meteor::getHP() const
{
    return this->health;
}
