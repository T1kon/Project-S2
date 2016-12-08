#include "Game.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "shipplayer.h"
#include <QDebug>

Game::Game(){

    setFocusPolicy(Qt::StrongFocus);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 10000, 10000);

    setScene(scene);

    setFixedSize(800, 600);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ShipPlayer * p = new ShipPlayer(400, 400, 0);

    centerOn(p);
    QPointF * point = new QPointF(p->x(), p->y());
    timer = new QTimer();
    //connect(timer, SIGNAL(timeout()), this, SLOT(bld(point)));
    timer->start(1000/60);

    scene->addItem(p);
    p->setFlag(QGraphicsItem::ItemIsFocusable);
    p->setFocus();

    QGraphicsRectItem * rect = new QGraphicsRectItem();
    rect->setRect(0, 0, 100, 100);
    rect->setPos(500, 500);
    scene->addItem(rect);


}

void Game::bld(QPointF f)
{
    centerOn(f);
    qDebug() << f;
}
