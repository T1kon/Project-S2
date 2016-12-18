#include "meteor.h"

Meteor::Meteor(double x, double y, int health)
{
    setPixmap(QPixmap(":/images/meteor.png"));
    setOffset(-20.5, -20.5);
    setX(x);
    setY(y);
    this->health = health;
}



int Meteor::type() const
{
    return Type;
}

void Meteor::reduceHP()
{
    this->health--;
    if (this->health <= 0){
        Explosion * exp = new Explosion(this->x(), this->y());
        scene()->addItem(exp);
        scene()->removeItem(this);
        delete this;
    }
}

unsigned int Meteor::getHP() const
{
    return this->health;
}
