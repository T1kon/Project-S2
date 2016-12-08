#ifndef METEOR_H
#define METEOR_H


#include  <QGraphicsPixmapItem>

class Meteor : public QGraphicsPixmapItem{
public:
    Meteor(double x, double y, int healthPoint);

private:
    double x;
    double y;
    int healthPoint;
};

#endif // METEOR_H
