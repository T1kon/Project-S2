#ifndef SHIPAI_H
#define SHIPAI_H

#include "ship.h"
#include "counter.h"

class ShipAI: public Ship
{
private:
public:
    enum { Type = UserType + 2 };
    ShipAI();
    ~ShipAI();
    Counter<ShipAI> counter;
};

#endif // SHIPAI_H
