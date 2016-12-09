#include "shipai.h"

ShipAI::ShipAI(double x, double y, double angle): Ship(x,y,angle)
{
    if (counter.getCount() < MAX_COUNT){

    }
    else{
        delete this;
    }
    foreach (QGraphicsItem * item, scene()->items()) {

    }
}

ShipAI::~ShipAI()
{
}

template<> int Counter<ShipAI>::count=0;
