#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>
#include <mainwindow.h>

namespace Ui {
class gameOver;
}

class gameOver : public QDialog
{
    Q_OBJECT

public:
    explicit gameOver(QString name, int val, QWidget *parent = 0);
    ~gameOver();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::gameOver *ui;
    QString username;
    int score;
};

#endif // GAMEOVER_H
