#ifndef METEOR_H
#define METEOR_H


#include  <QGraphicsPixmapItem>
#include "counter.h"

class Meteor : public QGraphicsPixmapItem{
public:
    enum { Type = UserType + 1 };
    Meteor(double x, double y, int health);
    virtual int type() const;
    void reduceHP();
    unsigned int getHP() const;
    static int getCount(){return Counter<Meteor>::getCount();}

private:
    double x;
    double y;
    unsigned int health;
    Counter<Meteor> counter;
};

#endif // METEOR_H
