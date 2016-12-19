#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMessageBox>
#include <QTimer>

#include "shipplayer.h"
#include "meteor.h"
#include "shipai.h"
#include <ctime>
#include <cstdlib>

class Game: public QGraphicsView{
    Q_OBJECT
private:
    ShipPlayer * p;
    unsigned int score = 0;
public:
    Game();

    QGraphicsScene * scene;

   // void keyPressEvent(QKeyEvent *event);

public slots:
    void moveCam();
    void spawn();

};

#endif // GAME_H
