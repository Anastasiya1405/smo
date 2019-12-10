#include "stepwindow.h"
#include "ui_stepwindow.h"
#include "mainwindow.h"
#include <iostream>
#include <QFrame>


StepWindow::StepWindow(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::StepWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

StepWindow::~StepWindow()
{
  delete ui;
}

void StepWindow::addHorizontalLines()
{
    QPen penBlack(Qt::black);
    QPen penRed(Qt::red);
    penBlack.setWidth(2);

    for (int i=0; i <= numSources_ + numDevice_ + numBufer_; i++)
    {
        scene->addLine(QLineF(73, i * scaleY + 20 , (numApplications_ / numSources_) * scaleX * 1.5, i * scaleY+20), penBlack);
    }
};

void StepWindow::addLineName()
{
    int lineIndex = 0;

    for (int i=0; i < numSources_; i++) {
        QGraphicsTextItem *textTmp = scene->addText(("Source №" + std::to_string(i+1)).c_str());
        textTmp->setX(0);
        textTmp->setY(lineIndex * scaleY);
        lineIndex++;
    }
    for (int i=0; i < numBufer_; i++) {
        QGraphicsTextItem *textTmp = scene->addText(("Buffer №" + std::to_string(i+1)).c_str());
        textTmp->setX(0);
        textTmp->setY(lineIndex * scaleY);
        lineIndex++;
    }
    for (int i=0; i < numDevice_; i++) {
        QGraphicsTextItem *textTmp = scene->addText(("Device №" + std::to_string(i+1)).c_str());
        textTmp->setX(0);
        textTmp->setY(lineIndex * scaleY);
        lineIndex++;
    }
    QGraphicsTextItem *cancel = scene->addText("Cancel:");
    cancel->setX(0);
    cancel->setY(lineIndex*scaleY);
};

void StepWindow::addEvent(double time, int object)
{
    QPen penRed(Qt::red);
    scene->addLine(QLineF(time * scaleX + 10, object * scaleY + 20 ,time * scaleX + 10, object * scaleY), penRed);
}


void StepWindow::connectTwoEvents(double time1, double time2, int object)
{
    QPen penRed(Qt::red);
    scene->addLine(QLineF(time1 * scaleX + 10, object * scaleY ,time2 * scaleX + 10, object * scaleY), penRed);
}

void StepWindow::addDashLine(double time, int object1, int object2)
{
    QPen penBlack(Qt::black);
    penBlack.setStyle(Qt::DashLine);
    scene->addLine(QLineF(time * scaleX + 10, object1 * scaleY + 20 ,time * scaleX + 10, object2 * scaleY + 20), penBlack);
}


void StepWindow::printEventInfo(double time, int object, int source, int applicationNum)
{
    QGraphicsTextItem *textTmp = scene->addText((std::to_string(source+1) + "." + std::to_string(applicationNum)).c_str());
    textTmp->setX(time * scaleX);
    textTmp->setY(object*scaleY - 20);
}



void StepWindow::on_pushButton_clicked()
{

    numSources_ = (static_cast<MainWindow*>(this->parent()))->getNumSources();
    numBufer_ = (static_cast<MainWindow*>(this->parent()))->getNumBufer();
    numDevice_ = (static_cast<MainWindow*>(this->parent()))->getNumHandler();
    numApplications_ = (static_cast<MainWindow*>(this->parent()))->getNumApplication();

    addHorizontalLines();
    addLineName();
    addEvent(parametr,0);
    parametr++;
    //printEventInfo(parametr,1,1,1)
//    addEvent(1,3);
//    addEvent(2,5);
//    addEvent(2,0);
//    addEvent(1,5);
//    addEvent(0,5);
//    addDashLine(2,0,5);
//    connectTwoEvents(2,1,5);
//    printEventInfo(1,3,1,1);
    //ui->graphicsView->setScene(scene);
}
