#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(256, 300);
    ui->playButton->setEnabled(false);
    loadScore();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadScore()
{
    std::string filename = "E:/c++/Project-S2/saves.data";
    std::ifstream infile(filename);
    std::string temp[800];
    int i = 0;
    if (infile){
        while(std::getline(infile, temp[i])){
            for (int j =0; j < temp[i].length(); ++j){
                temp[i][j] -= 10;
            }
            i++;
        }
    }
    infile.close();
    QString str;
    for (int j = 0; j < i; ++j){
        str += QString::fromStdString(temp[j]+'\n');
    }
    ui->textBrowser->setText(str);
}

void MainWindow::on_playButton_clicked()
{
    Game * game = new Game(ui->lineEdit->text());
    game->show();
    this->close();
}

void MainWindow::on_lineEdit_textChanged()
{
    if (!ui->lineEdit->text().isEmpty()){
        ui->playButton->setEnabled(true);
    }
    else{
        ui->playButton->setEnabled(false);
    }
}

void MainWindow::newGame()
{
    this->show();
}
