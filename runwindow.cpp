#include "runwindow.h"
#include "ui_runwindow.h"
#include "mainwindow.h"
#include <QString>
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

#include <QApplication>

RunWindow::RunWindow(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::RunWindow)

{
  ui->setupUi(this);
  //MainWindow* w = (MainWindow*)(parent);
  numSources_ = (static_cast<MainWindow*>(this->parent()))->getNumSources();
  numBufer_ = (static_cast<MainWindow*>(this->parent()))->getNumBufer();
  numHandler_ = (static_cast<MainWindow*>(this->parent()))->getNumHandler();
  numApplication_ = (static_cast<MainWindow*>(this->parent()))->getNumApplication();
  alpha_ = (static_cast<MainWindow*>(this->parent()))->getAlpha();
  beta_ = (static_cast<MainWindow*>(this->parent()))->getBeta();
  lambda_ = (static_cast<MainWindow*>(this->parent()))->getLambda();

  ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
  ui->tableWidget->setRowCount(numSources_);
  ui->tableWidget->setColumnCount(8);
  ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("AppsCount"));
  ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Refused Count"));
  ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Accepted Count"));
  ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("P Of Failure"));
  ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Time In System"));
  ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("HandlingTime"));
  ui->tableWidget->setHorizontalHeaderItem(6, new QTableWidgetItem("Buffering Time"));
  ui->tableWidget->setHorizontalHeaderItem(7, new QTableWidgetItem("dispersion"));
  ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

  ui->tableWidget_2->setSelectionMode(QAbstractItemView::SingleSelection);
  ui->tableWidget_2->setRowCount(numHandler_);
  ui->tableWidget_2->setColumnCount(1);
  ui->tableWidget_2->setHorizontalHeaderItem(0, new QTableWidgetItem("EmploymentRate"));
  ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

//  settings_t set = w->getSettings();
//  Observer obs = cmo::modeling(set);
//  double p1 = (double)(obs.getRejectedReqs(0)) / (double)(obs.getGeneratedReqs(0));
//  double p0 = 1;
//  while (std::abs(p1 - p0) > p1 * 0.01 && p1 > 0.00001)
//  {
//    size_t N = 1.643 * 1.643 * (1 - p1) / (p1 * 0.01);
//    set.requestNum = N;
//    obs = cmo::modeling(set);
//    p0 = p1;
//    p1 = (double)(obs.getRejectedReqs(0)) / (double)(obs.getGeneratedReqs(0));
//  }

//  for (size_t i = 0; i < w->getSettings().sourceNum; i++)
//  {
//    QString str(("Src" + std::to_string(i + 1)).data());
//    ui->tableWidget->setVerticalHeaderItem(i, new QTableWidgetItem(str));
//    str.setNum((double)(obs.getGeneratedReqs(i)));
//    ui->tableWidget->setItem(i, 0, new QTableWidgetItem(str));
//    str.setNum((double)(obs.getRejectedReqs(i)) / (double)(obs.getGeneratedReqs(i)), 'f', 4);
//    ui->tableWidget->setItem(i, 1, new QTableWidgetItem(str));
//    str.setNum(obs.getAverageExistenceTime(i), 'f', 4);
//    ui->tableWidget->setItem(i, 2, new QTableWidgetItem(str));
//    str.setNum(obs.getAverageWaitTime(i), 'f', 4);
//    ui->tableWidget->setItem(i, 3, new QTableWidgetItem(str));
//    str.setNum(obs.getAverageProcessTime(i), 'f', 4);
//    ui->tableWidget->setItem(i, 4, new QTableWidgetItem(str));
//    str.setNum(obs.getWaitTimeDisp(i), 'f', 4);
//    ui->tableWidget->setItem(i, 5, new QTableWidgetItem(str));
//    str.setNum(obs.getProcessTimeDisp(i), 'f', 4);
//    ui->tableWidget->setItem(i, 6, new QTableWidgetItem(str));
//  }

//  for (size_t i = 0; i < w->getSettings().deviceNum; i++)
//  {
//    QString str(("Dev" + std::to_string(i + 1)).data());
//    ui->tableWidget_2->setVerticalHeaderItem(i, new QTableWidgetItem(str));
//    str.setNum(obs.getDeviceBusyTime(i) / obs.getWorkTime(), 'f', 4 );
//    ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(str));
//  }

}

RunWindow::~RunWindow()
{
  delete ui;
}

void RunWindow::on_pushButton_clicked()
{
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

      std::list <StepStructure> :: iterator it;
      //int i = 0;
      for (it = StepList.begin(); it != StepList.end(); it++) {
          std::cout <<"huynya "<< it->time_ << '\n';
       }

      for (size_t i = 0; i < numSources_; i++)
       {
         QString str(("Src" + std::to_string(i + 1)).data());
         ui->tableWidget->setVerticalHeaderItem(i, new QTableWidgetItem(str));

         str.setNum((double)(functionalModule.data_.sourcesData[i].generatedAppsCount));
         ui->tableWidget->setItem(i, 0, new QTableWidgetItem(str));

         str.setNum((double)(functionalModule.data_.sourcesData[i].refusedAppsCount));
         ui->tableWidget->setItem(i, 1, new QTableWidgetItem(str));

         str.setNum((double)(functionalModule.data_.sourcesData[i].generatedAppsCount -
                    functionalModule.data_.sourcesData[i].refusedAppsCount));
         ui->tableWidget->setItem(i, 2, new QTableWidgetItem(str));

         str.setNum(functionalModule.data_.getProbabilityOfFailure(i));
         ui->tableWidget->setItem(i, 3, new QTableWidgetItem(str));

         str.setNum(functionalModule.data_.getAverageTimeInSystem(i));
         ui->tableWidget->setItem(i, 4, new QTableWidgetItem(str));

         str.setNum(functionalModule.data_.getAverageHandlingTime(i));
         ui->tableWidget->setItem(i, 5, new QTableWidgetItem(str));

         str.setNum(functionalModule.data_.getAverageBufferingTime(i));
         ui->tableWidget->setItem(i, 6, new QTableWidgetItem(str));

         str.setNum(functionalModule.data_.getAverageBufferingTime(i) / functionalModule.data_.getAverageTimeInSystem(i));
         ui->tableWidget->setItem(i, 7, new QTableWidgetItem(str));
       }

       for (size_t i = 0; i < numHandler_; i++)
       {
         QString str(("Dev" + std::to_string(i + 1)).data());
         ui->tableWidget_2->setVerticalHeaderItem(i, new QTableWidgetItem(str));

         str.setNum(functionalModule.data_.getEmploymentRate(i));
         ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(str));
       }
}
