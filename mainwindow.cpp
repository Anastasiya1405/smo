#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

int load(int numSources, int numBufer, int numHandler, int numApplication, double lambda, double alpha, double beta);
//int load();
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_modelling_clicked()
{
//    int numSources = 3;
//    int numBufer = 10;
//    int numHandler = 2;
//    int numApplication = 10000;
//    double lambda = 3.0;
//    double alpha = 1.0;
//      double beta = 3.0;
    int numSources =ui->numSource->toPlainText().toInt();
    int numApplication = ui->numAp->toPlainText().toInt();
   int numBufer = ui->numBufer->toPlainText().toInt();
    int numHandler = ui->numHandler->toPlainText().toInt();
    double lambda = ui->lambda->toPlainText().toDouble();
    double alpha = ui->alpha->toPlainText().toDouble();
   double beta = ui->beta->toPlainText().toDouble();
     //std::cout << lambda << '\n' << alpha << '\n';

   int a = load(numSources, numBufer, numHandler, numApplication, lambda, alpha, beta);
   this->close();
    //sint a = load();

}
