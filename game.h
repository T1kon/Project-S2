#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <shipplayer.h>

class Game: public QGraphicsView{
    Q_OBJECT
private:
    ShipPlayer * p;
    double rotation;
public:
    Game();

    QGraphicsScene * scene;

public slots:
    void moveCam();
};

#endif // GAME_H
