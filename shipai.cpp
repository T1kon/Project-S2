#include "shipai.h"

ShipAI::ShipAI()
{
    if (counter.getCount() < 2){

    }
    else{
        delete this;
    }
}

ShipAI::~ShipAI()
{
}

template<> int Counter<ShipAI>::count=0;
