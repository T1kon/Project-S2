#ifndef METEOR_H
#define METEOR_H


#include  <QGraphicsPixmapItem>

class Meteor : public QGraphicsPixmapItem{
public:
    Meteor(int x, int y, int healthPoint);

private:
    int x;
    int y;
    int healthPoint;
};

#endif // METEOR_H
