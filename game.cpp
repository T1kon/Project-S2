#include "Game.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QDesktopWidget>
#include <QKeyEvent>
#include <math.h>


Game::Game(){

    srand(static_cast<unsigned int>(time(NULL)));

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
    //qDebug() << ai1->getCount();


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

    qDebug() << "ShipCount: "<< ShipAI::getCount();
    qDebug() << "MeteorCount: "<< Meteor::getCount();
    double angle = rand() % 360;
    double meteorX = p->x() + cos(angle/180*M_PI) * (rand() % 300 + 700);
    double meteorY = p->y() + sin(angle/180*M_PI) * (rand() % 300 + 700);
    Meteor * meteor = new Meteor(meteorX, meteorY, 1);
    scene->addItem(meteor);


}

