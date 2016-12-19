#include "gameover.h"
#include "ui_gameover.h"

gameOver::gameOver(QString name, int val, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameOver)
{
    score = val;
    username = name;

    ui->setupUi(this);
    this->setWindowTitle("Game Over!");
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setText(username+", your score is: "+QString::number(score));
}

gameOver::~gameOver()
{
    delete ui;
}

void gameOver::on_pushButton_clicked()
{
    Game * game = new Game(username);
    game->show();
    this->close();
}

void gameOver::on_pushButton_2_clicked()
{
    this->close();
}
