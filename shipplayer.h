#ifndef SHIPPLAYER_H
#define SHIPPLAYER_H

#include "ship.h"
#include <QMap>

class ShipPlayer: public Ship
{
private:

public:
    ShipPlayer(double x, double y, double angle);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
};

#endif // SHIPPLAYER_H
