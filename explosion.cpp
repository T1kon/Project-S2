#include "explosion.h"

Explosion::Explosion(double x, double y)
{
    setPos(x, y);
    setPixmap(QPixmap(":/images/explosion.png"));
    setOffset(-22.5, -28.5);

    lifetime = new QTimer();
    connect(lifetime, SIGNAL(timeout()), this, SLOT(deleteObject()));
    lifetime->start(3000);
}

void Explosion::deleteObject()
{
    scene()->removeItem(this);
    delete this;
}
