#include "Game.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QDesktopWidget>
#include <QKeyEvent>
#include <math.h>


Game::Game(QString name){

    username = name;
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

    QTimer * timer1 = new QTimer();
    connect(timer1, SIGNAL(timeout()), this, SLOT(moveCam()));
    timer1->start(1000/12000);

    scene->addItem(p);
    p->setFlag(QGraphicsItem::ItemIsFocusable);
    p->setFocus();

    QTimer * spawnTimer = new QTimer();

    connect(spawnTimer, SIGNAL(timeout()),
            this,SLOT(spawn()));
    spawnTimer->start(1000);
}

int Game::getScore()
{
    return score;
}

/*&void Game::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Escape){
        delete this;
    }
}*/


void Game::moveCam()
{

    if (p->getHP() > 0){
        centerOn(p->x(), p->y());
        p->setFocus();
    }
}

void Game::spawn()
{
    if (p->getHP() > 0){
        score++;
        qDebug() << "Score:" << score;
        //qDebug() << "ShipCount: "<< ShipAI::getCount();
        //qDebug() << "MeteorCount: "<< Meteor::getCount();
        if (Meteor::getCount() < 2000){
            double angle = (rand() % 360) ;
            double meteorX = p->x() + cos(angle/180*M_PI) * (rand() % 300 + 1050);
            double meteorY = p->y() + sin(angle/180*M_PI) * (rand() % 300 + 1050);
            Meteor * meteor = new Meteor(meteorX, meteorY, 1);
            scene->addItem(meteor);
        }
        if (ShipAI::getCount() < 20){
            double angle = (rand() % 720) /2;
            double shipX = p->x() + cos(angle/180*M_PI) * (rand() % 200 + 1050);
            double shipY = p->y() + sin(angle/180*M_PI) * (rand() % 200 + 1050);
            ShipAI * ai = new ShipAI(shipX, shipY, angle);
            scene->addItem(ai);
        }
    }
    else{
        gameOver * window = new gameOver(username, score);
        window->show();
//        QMessageBox *mb = new QMessageBox;
//        mb->setWindowTitle("Game over!");
//        mb->setText("Your score is: " + QString::number(score));
//        mb->show();
        delete this;
    }
}

