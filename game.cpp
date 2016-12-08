#include "Game.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "shipplayer.h"

Game::Game(){

    setFocusPolicy(Qt::StrongFocus);
    startTimer(1000/60);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);

    setScene(scene);

    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QGraphicsRectItem * rect = new QGraphicsRectItem();
    rect->setRect(0,0,100,100);

    scene->addItem(rect);

    ShipPlayer * p = new ShipPlayer(0,0,0);
    scene->addItem(p);
    p->setFlag(QGraphicsItem::ItemIsFocusable);
    p->setFocus();
}
