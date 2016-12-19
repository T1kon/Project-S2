#include "gameover.h"
#include "ui_gameover.h"
#include <QDebug>

gameOver::gameOver(QString name, int val, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameOver)
{
    score = val;
    username = name.toStdString();

    ui->setupUi(this);
    this->setWindowTitle("Game Over!");
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setText(QString::fromStdString(username)+", your score is: "+QString::number(score));
    saveRecord();
    loadRecord();
}

gameOver::~gameOver()
{
    delete ui;
}

void gameOver::saveRecord()
{
    std::string filename = "E:/c++/Project-S2/saves.data";
    std::ifstream infile(filename);
    std::string temp[800];
    int i = 0;
    if (infile){
        while(std::getline(infile, temp[i])){
            i++;
        }
    }
    infile.close();
    std::string tmp = std::to_string(score);
    for (int j = 0; j < tmp.length(); ++j){
        tmp[j] += koef;
    }
    temp[i] = (tmp)+char(42);
    for(int j = 0; j < username.length(); ++j){
        temp[i] += (username[j] + koef);
    }
    ++i;
    std::ofstream offile(filename);
    if (offile){
        for (int j = 0; j < i; ++j){
            offile << temp[j] << '\n';
        }
    }
    offile.close();
}

void gameOver::loadRecord()
{
    std::string filename = "E:/c++/Project-S2/saves.data";
    std::ifstream infile(filename);
    std::string temp[800];
    int i = 0;
    if (infile){
        while(std::getline(infile, temp[i])){
            for (int j =0; j < temp[i].length(); ++j){
                temp[i][j] -= koef;
            }
            qDebug() << QString::fromStdString(temp[i]);
            i++;
        }
    }
    infile.close();
}

void gameOver::on_pushButton_clicked()
{
    Game * game = new Game(QString::fromStdString(username));
    game->show();
    delete this;
    //this->close();
}

void gameOver::on_pushButton_2_clicked()
{
    this->close();
}
