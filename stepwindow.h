#ifndef STEPWINDOW_H
#define STEPWINDOW_H

#include <QWidget>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include "step.hpp"


namespace Ui {
  class StepWindow;
}
class StepWindow : public QDialog
{
  Q_OBJECT

public:
  explicit StepWindow(QWidget *parent = 0);
  ~StepWindow();
   void addHorizontalLines();
   void addLineName();
   void addEvent(double time, int object);
   void connectTwoEvents(double time1, double time2, int object);
   void printEventInfo(double time, int object, int source, int applicationNum);
   void addDashLine(double time, int object1, int object2);
private slots:
  void on_pushButton_clicked();

private:
  Ui::StepWindow *ui;
     int currentStep = 1;
     float leftTime;
     float rightTime;

     int scaleY = 50;
     int scaleX = 50*5;
     int dashHeight = 25;
     int numSources_;
     int numApplication_;
     int numBufer_;
     int numHandler_;
     double lambda_;
     double alpha_;
     double beta_;

     double parametr = 0.0;

     QGraphicsScene *scene;
 };
































#endif // STEPWINDOW_H
