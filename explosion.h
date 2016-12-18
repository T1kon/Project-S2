#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>

class Explosion: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QTimer * lifetime;
public:
    Explosion(double x, double y);
public slots:
    void deleteObject();
};

#endif // EXPLOSION_H
