#ifndef SHIPAI_H
#define SHIPAI_H

#include "ship.h"
#include "counter.h"
#include <QTimer>
#include <QGraphicsScene>

class ShipAI: public Ship
{
    Q_OBJECT
private:
    double targetX;
    double targetY;
    double targetAngle;
    const int MAX_COUNT = 5;
    QTimer * logicTimer;
    Counter<ShipAI> counter;
public:
    enum { Type = UserType + 2 };
    ShipAI(double x, double y, double angle);
    ~ShipAI();
    static int getCount(){return Counter<ShipAI>::getCount();}
    double countAngle(double x, double y);
    double currentAngle(double angle);
    virtual int type() const;
    bool checkShootingDistance(double x, double y);
public slots:
    void refreshLogics();
};

#endif // SHIPAI_H
