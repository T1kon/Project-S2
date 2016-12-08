#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>

class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    const double SPEED = 20.0;
    QTimer * lifeTime;
public:
    Bullet(double x, double y, double angle);
public slots:
    void moveBullet();
    void deleteBullet();
};

#endif // BULLET_H
