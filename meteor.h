#ifndef METEOR_H
#define METEOR_H


#include  <QGraphicsPixmapItem>

class Meteor : public QGraphicsPixmapItem{
public:
    enum { Type = UserType + 1 };
    Meteor(double x, double y, int healthPoint);

private:
    double x;
    double y;
    int healthPoint;
public:
    virtual int type() const;
};

#endif // METEOR_H
