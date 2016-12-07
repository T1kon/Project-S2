#ifndef SHIPAI_H
#define SHIPAI_H

#include "ship.h"
#include "counter.h"

class ShipAI: public Ship
{
private:
public:
    ShipAI();
    ~ShipAI();
    Counter<ShipAI> counter;
};

#endif // SHIPAI_H
