#ifndef SHIPPLAYER_H
#define SHIPPLAYER_H

#include "ship.h"

class ShipPlayer: public Ship
{
private:

public:
    enum { Type = UserType + 3 };
    ShipPlayer(double x, double y, double angle);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

    // Ship interface
    void deleteShip();

    // QGraphicsItem interface
    int type() const;

};

#endif // SHIPPLAYER_H
