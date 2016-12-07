#include "mainwindow.h"
#include <QApplication>
#include "ship.h"
#include "shipai.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    ShipAI * x1 = new ShipAI();
    ShipAI * x2 = new ShipAI();
    ShipAI * x3 = new ShipAI();
    delete x3;
    qDebug() << x1->counter.getCount();
    //ShipAI x;
    return a.exec();
}
