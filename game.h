#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QObject>
#include <shipplayer.h>

class Game: public QGraphicsView{
        Q_OBJECT
public:
    Game();

    QGraphicsScene * scene;
    QTimer * timer;

public slots:
    void bld(QPointF f);
};

#endif // GAME_H
