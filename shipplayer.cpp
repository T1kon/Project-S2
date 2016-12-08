#include "shipplayer.h"
#include <QDebug>
#include <QKeyEvent>

ShipPlayer::ShipPlayer(double x, double y, double angle): Ship(x,y,angle)
{
    CanRotateL = false;
    CanRotateR = false;
    canMoveB = false;
    canMoveF = false;
}

void ShipPlayer::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "key is pressed";

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
}
