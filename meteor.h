#ifndef METEOR_H
#define METEOR_H


#include  <QGraphicsPixmapItem>

class Meteor : public QGraphicsPixmapItem{
public:
    enum { Type = UserType + 1 };
    Meteor(double x, double y, int health);

private:
    double x;
    double y;
    unsigned int health;
public:
    virtual int type() const;
    void reduceHP();
    unsigned int getHP() const;
};

#endif // METEOR_H
