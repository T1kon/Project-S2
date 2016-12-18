#ifndef METEOR_H
#define METEOR_H


#include  <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include "counter.h"
#include "explosion.h"

class Meteor :public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    enum { Type = UserType + 1 };
    Meteor(double x, double y, int health);
    virtual int type() const;
    void reduceHP();
    unsigned int getHP() const;
    static int getCount(){return Counter<Meteor>::getCount();}

private:
    unsigned int health;
    Counter<Meteor> counter;
};

#endif // METEOR_H
