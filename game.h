#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMessageBox>
#include <QTimer>

#include "shipplayer.h"
#include "meteor.h"
#include "shipai.h"
#include "gameover.h"
#include <ctime>
#include <cstdlib>

class Game: public QGraphicsView{
    Q_OBJECT
private:
    ShipPlayer * p;
    unsigned int score = 0;
    QString username;
    QTimer * timer1;
    QTimer * spawnTimer;
public:
    Game(QString name);
    QGraphicsScene * scene;
    void stopTimer();
    int getScore();
   // void keyPressEvent(QKeyEvent *event);

public slots:
    void moveCam();
    void spawn();

};

#endif // GAME_H
