#include "Game.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QDesktopWidget>
#include <QKeyEvent>


Game::Game(){
    setFocusPolicy(Qt::StrongFocus);
    setCursor(Qt::BlankCursor);
    QDesktopWidget widget;
    QRect mainScreenSize = widget.availableGeometry(widget.primaryScreen());
    setFixedSize(mainScreenSize.width()-10, mainScreenSize.height()-35);
    //showFullScreen();

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 10000, 10000);
    scene->setBackgroundBrush(QBrush(QImage(":/images/space.png")));

    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //==========================================================

    p = new ShipPlayer(5000, 5000, 0);

    ShipAI * ai1 = new ShipAI(5200,5200,0);
    ShipAI * ai2 = new ShipAI(5250,5250,0);
    ShipPlayer * p2 = new ShipPlayer(5300,5300,0);
    scene->addItem(ai1);
    scene->addItem(ai2);
    scene->addItem(p2);


    QTimer * timer1 = new QTimer();
    connect(timer1, SIGNAL(timeout()), this, SLOT(moveCam()));
    timer1->start(1000/12000);

    scene->addItem(p);
    p->setFlag(QGraphicsItem::ItemIsFocusable);

    QTimer * spawnTimer = new QTimer();

    connect(spawnTimer, SIGNAL(timeout()),
            this,SLOT(spawn()));
    spawnTimer->start(1000);
}

/*&void Game::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Escape){
        delete this;
    }
}*/


void Game::moveCam()
{
    centerOn(p->x(), p->y());
    p->setFocus();
}

void Game::spawn()
{
    srand(static_cast<unsigned int>(time(NULL)));
    Meteor * meteor = new Meteor(p->x()+float((rand()%500)-250),p->y()+float((rand()%500)-250),1);
    scene->addItem(meteor);


}

