#ifndef SHIPAI_H
#define SHIPAI_H

#include "ship.h"
#include "counter.h"

class ShipAI: public Ship
{
private:
    Ship * target;
    const int MAX_COUNT = 5;
public:
    enum { Type = UserType + 2 };
    ShipAI(double x, double y, double angle);
    ~ShipAI();
    Counter<ShipAI> counter;
};

#endif // SHIPAI_H
