#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

int load(int numSources, int numBufer, int numHandler, size_t numApplication, double lambda, double alpha, double beta);
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
    int numSources =ui->numSource->toPlainText().toInt();
    size_t numApplication = ui->numAp->toPlainText().toInt();
   int numBufer = ui->numBufer->toPlainText().toInt();
    int numHandler = ui->numHandler->toPlainText().toInt();
    double lambda = ui->lambda->toPlainText().toDouble();
    double alpha = ui->alpha->toPlainText().toDouble();
   double beta = ui->beta->toPlainText().toDouble();

   int a = load(numSources, numBufer, numHandler, numApplication, lambda, alpha, beta);
   this->close();
}

void MainWindow::on_modelling_2_clicked()
{

}
