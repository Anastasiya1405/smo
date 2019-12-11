#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
//std::list<StepStructure> StepList;
//int load(int numSources, int numBufer, int numHandler, size_t numApplication, double lambda, double alpha, double beta);
//int load();
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    runWindow = nullptr;
    stepWindow = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete runWindow;
    delete stepWindow;
}

int MainWindow::getNumSources()
{
  return numSources_;
};

int MainWindow::getNumApplication()
{
  return numApplication_;
};

int MainWindow::getNumBufer()
{
    return numBufer_;
};

int MainWindow::getNumHandler()
{
    return numHandler_;
};

double MainWindow::getLambda()
{
    return lambda_;
};

double MainWindow::getAlpha()
{
    return alpha_;
};

double MainWindow::getBeta()
{
    return beta_;
};

void MainWindow::on_modelling_clicked()
{
   numSources_ =ui->numSource->toPlainText().toInt();
   numApplication_ = ui->numAp->toPlainText().toInt();
   numBufer_ = ui->numBufer->toPlainText().toInt();
   numHandler_ = ui->numHandler->toPlainText().toInt();
   lambda_ = ui->lambda->toPlainText().toDouble();
   alpha_ = ui->alpha->toPlainText().toDouble();
   beta_ = ui->beta->toPlainText().toDouble();
   //load(numSources_, numBufer_, numHandler_, numApplication_, lambda_, alpha_, beta_);
   if (this->runWindow != nullptr)
         delete runWindow;
       this->runWindow = new RunWindow(this);
       runWindow->show();

   //this->close();
}

void MainWindow::on_StepByStep_clicked()
{
    numSources_ =ui->numSource->toPlainText().toInt();
    numApplication_ = ui->numAp->toPlainText().toInt();
    numBufer_ = ui->numBufer->toPlainText().toInt();
    numHandler_ = ui->numHandler->toPlainText().toInt();
    lambda_ = ui->lambda->toPlainText().toDouble();
    alpha_ = ui->alpha->toPlainText().toDouble();
    beta_ = ui->beta->toPlainText().toDouble();
    if (this->stepWindow != nullptr)
          delete stepWindow;
        this->stepWindow = new StepWindow(this);
        stepWindow->show();

}
