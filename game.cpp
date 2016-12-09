#include "Game.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "shipplayer.h"
#include "meteor.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QKeyEvent>

Game::Game(){
    setFocusPolicy(Qt::StrongFocus);
    this->setCursor(Qt::BlankCursor);
    QDesktopWidget widget;
    QRect mainScreenSize = widget.availableGeometry(widget.primaryScreen());
    setFixedSize(mainScreenSize.width(), mainScreenSize.height());
    showFullScreen();

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 10000, 10000);
    scene->setBackgroundBrush(QBrush(QImage(":/images/space.png")));

    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //==========================================================

    p = new ShipPlayer(5000, 5000, 0);

    QTimer * timer1 = new QTimer();
    connect(timer1, SIGNAL(timeout()), this, SLOT(moveCam()));

    timer1->start(1000/12000);

    scene->addItem(p);
    p->setFlag(QGraphicsItem::ItemIsFocusable);
    p->setFocus();

    Meteor * m1 = new Meteor(5100, 5100, 4);
    scene->addItem(m1);
}

void Game::moveCam()
{
    centerOn(p->x(), p->y());
}
