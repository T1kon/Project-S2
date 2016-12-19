#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(256, 200);  
    ui->playButton->setEnabled(false);
    //connect(gameOver::, SIGNAL(gameover()), this, SLOT(newGame());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_playButton_clicked()
{
    Game * game = new Game(ui->lineEdit->text());
    this->hide();
    game->show();
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
