#include "stepwindow.h"
#include "ui_stepwindow.h"
#include "mainwindow.h"
#include <iostream>
#include <QFrame>
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include "step.hpp"
#include "/Users/georgy/University/ArchitectureOfSoftwareSystems/smo/headers/Source.hpp"
#include "/Users/georgy/University/ArchitectureOfSoftwareSystems/smo/headers/Handler.hpp"
#include "/Users/georgy/University/ArchitectureOfSoftwareSystems/smo/headers/Buffer.hpp"
#include "/Users/georgy/University/ArchitectureOfSoftwareSystems/smo/headers/FunctionalModule.hpp"
#include "/Users/georgy/University/ArchitectureOfSoftwareSystems/smo/headers/RingSelection.hpp"
#include "/Users/georgy/University/ArchitectureOfSoftwareSystems/smo/headers/FreeAddition.hpp"
#include "/Users/georgy/University/ArchitectureOfSoftwareSystems/smo/headers/RingAdd.h"



StepWindow::StepWindow(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::StepWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    numSources_ = (static_cast<MainWindow*>(this->parent()))->getNumSources();
    numBufer_ = (static_cast<MainWindow*>(this->parent()))->getNumBufer();
    numHandler_ = (static_cast<MainWindow*>(this->parent()))->getNumHandler();
    numApplication_ = (static_cast<MainWindow*>(this->parent()))->getNumApplication();
    alpha_ = (static_cast<MainWindow*>(this->parent()))->getAlpha();
    beta_ = (static_cast<MainWindow*>(this->parent()))->getBeta();
    lambda_ = (static_cast<MainWindow*>(this->parent()))->getLambda();

    std::cout << "numSources = " << numSources_ << '\n'
              << "numBufer = " << numBufer_ << '\n'
              << "numHandler = " << numHandler_ << '\n'
              << "numApplication = "<< numApplication_ << '\n'
              << "lambda = " <<lambda_ << '\n'
              << "alpha = "<< alpha_ << '\n'
              << "beta = "<< beta_ << '\n';
    std::cout << '\n';
    std::srand(unsigned(std::time(nullptr)));

      std::shared_ptr<TimeBehaviour> exponentialTimeGenerator = std::make_shared<ExponentialTimeBehavior>();

      double a = alpha_;
      double b = beta_;
      std::shared_ptr<TimeBehaviour> infiniteUniformTimeGenerator = std::make_shared<InfiniteUniformTimeBehavior>(a, b);

       double intensity = lambda_;
      std::shared_ptr<TimeBehaviour> puassonTime = std::make_shared<PuassonTime>();

      std::vector<std::shared_ptr<Source>> sources;
      for (int i = 0; i <  numSources_; i++)
      {
          sources.push_back(std::make_shared<Source>(intensity, puassonTime));
      }

      //intensity = 8;
      std::vector<std::shared_ptr<Handler>> handlers;
      for (int i = 0; i < numHandler_; i++)
      {
          handlers.push_back(std::make_shared<Handler>(0, infiniteUniformTimeGenerator));
      };

      const size_t bufferSize = numBufer_;
      std::shared_ptr<SelectionStrategy> selectionStrategy = std::make_shared<RingSelection>();
      std::shared_ptr<AdditionStrategy> additionStrategy = std::make_shared<RingAdd>();
      std::shared_ptr<Buffer> buffer = std::make_shared<Buffer>(selectionStrategy, additionStrategy, bufferSize);

      FunctionalModule functionalModule(sources, buffer, handlers);
      //functionalModule.simulate(999999);
      functionalModule.totalGeneratedAppsSimulation(numSources_, numBufer_, numHandler_, numApplication_);
      for (size_t i = 0; i < sources.size(); ++i) {
        std::cout << "Stats for " << i+ 1 << " source:\n";
        std::cout << "\t generatedAppsCount = " << functionalModule.data_.sourcesData[i].generatedAppsCount << '\n';
        std::cout << "\t refusedAppsCount = " << functionalModule.data_.sourcesData[i].refusedAppsCount << '\n';
        //std::cout << "\t acceptedAppsCount = " << functionalModule.data_.sourcesData[i].acceptedAppsCount << '\n';
        std::cout << "\t acceptedAppsCount = " << functionalModule.data_.sourcesData[i].generatedAppsCount -
                     functionalModule.data_.sourcesData[i].refusedAppsCount  << '\n';
        std::cout << "\t getProbabilityOfFailure = " << functionalModule.data_.getProbabilityOfFailure(i) << '\n';
        std::cout << "\t averageTimeInSystem = " << functionalModule.data_.getAverageTimeInSystem(i) << '\n';
        std::cout << "\t averageHandlingTime = " << functionalModule.data_.getAverageHandlingTime(i) << '\n';
        std::cout << "\t averageBufferingTime = " << functionalModule.data_.getAverageBufferingTime(i) << '\n';
        std::cout << "\t dispersion = " <<
                     functionalModule.data_.getAverageBufferingTime(i) / functionalModule.data_.getAverageTimeInSystem(i)
                  << '\n';
        std::cout << '\n';
      }

      for (size_t i = 0; i < handlers.size(); ++i) {
        std::cout << "Stats for " << i + 1 << " handler:\n";
        std::cout << "\t getEmploymentRate = " << functionalModule.data_.getEmploymentRate(i) << '\n';
      }
      std::cout <<"55 "<< StepList.begin()->time_ << '\n';
      std::cout <<"55 "<< StepList.front().numSource_ +1<< '\n';
      std::cout <<"55 "<< StepList.end()->time_ << '\n';
      std::cout <<"55 "<< StepList.back().numSource_+1 << '\n';

//      std::list <StepStructure> :: iterator it;
//      //int i = 0;
//      for (it = StepList.begin(); it != StepList.end(); it++) {
//          std::cout <<"huynya "<< it->time_ << '\n';
//       }
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

    for (int i=0; i <= numSources_ + numHandler_ + numBufer_; i++)
    {
        scene->addLine(QLineF(73, i * scaleY + 20 , (numApplication_ / numSources_) * scaleX * 1.5, i * scaleY+20), penBlack);
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
    for (int i=0; i < numHandler_; i++) {
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
    scene->addLine(QLineF(time * scaleX + 73, object * scaleY + 20 ,time * scaleX + 73, object * scaleY), penRed);
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
    addHorizontalLines();
    addLineName();

    std::list <StepStructure> :: iterator it = StepList.begin();
    //int i = 0;
    //for (it = StepList.begin(); it != StepList.end(); it++) {
    QGraphicsTextItem *textTmp = scene->addText((std::to_string(it->numSource_)).c_str());

    textTmp->setX(currentStep * scaleX);
    textTmp->setY(currentStep * scaleY - 20);
    currentStep++;
//    std::cout <<"huynya "<< it->time_ << '\n';
//    it++;
//    }
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
