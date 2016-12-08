#include "Game.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "shipplayer.h"
#include <QDebug>

Game::Game(){
    rotation = 0;
    setFocusPolicy(Qt::StrongFocus);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 1000, 1000);

    setScene(scene);

    setFixedSize(800, 600);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    p = new ShipPlayer(400, 400, 0);

    centerOn(p);

    QTimer * timer1 = new QTimer();
    connect(timer1, SIGNAL(timeout()), this, SLOT(moveCam()));

    timer1->start(1000/12000);

    scene->addItem(p);
    p->setFlag(QGraphicsItem::ItemIsFocusable);
    p->setFocus();

    QGraphicsRectItem * rect = new QGraphicsRectItem();
    rect->setRect(0, 0, 100, 100);
    rect->setPos(500, 500);
    scene->addItem(rect);


}

void Game::moveCam()
{
    centerOn(p->x(), p->y());
}
