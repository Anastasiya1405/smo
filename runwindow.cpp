#include "runwindow.h"
#include "ui_runwindow.h"
#include "mainwindow.h"
#include <QString>

RunWindow::RunWindow(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::RunWindow)

{
  ui->setupUi(this);
  MainWindow* w = (MainWindow*)(parent);
  numSources_ = (static_cast<MainWindow*>(this->parent()))->getNumSources();
  numBufer_ = (static_cast<MainWindow*>(this->parent()))->getNumBufer();
  numDevice_ = (static_cast<MainWindow*>(this->parent()))->getNumHandler();
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
  ui->tableWidget_2->setRowCount(numDevice_);
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

}
