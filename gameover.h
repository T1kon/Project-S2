#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>
#include <mainwindow.h>
#include <iostream>
#include <fstream>
#include <string>

namespace Ui {
class gameOver;
}

class gameOver : public QDialog
{
    Q_OBJECT

public:
    explicit gameOver(QString name, int val, QWidget *parent = 0);
    ~gameOver();
    void saveRecord();
    void loadRecord();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::gameOver *ui;
    std::string username;
    int score;
    int koef = 10;
};

#endif // GAMEOVER_H
