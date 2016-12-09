#include "shipplayer.h"
#include <QKeyEvent>

ShipPlayer::ShipPlayer(double x, double y, double angle): Ship(x,y,angle)
{

}

void ShipPlayer::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up){
        canMoveF = true;
    }
    else if (event->key() == Qt::Key_Down){
        canMoveB = true;
    }
    else if (event->key() == Qt::Key_Left){
        CanRotateL = true;
    }
    else if (event->key() == Qt::Key_Right){
        CanRotateR = true;
    }
    else if (event->key() == Qt::Key_Space){
        CanShoot = true;
    }
}

void ShipPlayer::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up){
        canMoveF = false;
    }
    else if (event->key() == Qt::Key_Down){
        canMoveB = false;
    }
    else if (event->key() == Qt::Key_Left){
        CanRotateL = false;
    }
    else if (event->key() == Qt::Key_Right){
        CanRotateR = false;
    }
    else if (event->key() == Qt::Key_Space){
        CanShoot = false;
    }
}

int ShipPlayer::type() const
{
    return Type;
}
