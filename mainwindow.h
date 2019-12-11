#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stepwindow.h"
#include "runwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int getNumSources();
    int getNumApplication();
    int getNumBufer();
    int getNumHandler();
    double getLambda();
    double getAlpha();
    double getBeta();

    int numSources_;
    int numApplication_;
    int numBufer_;
    int numHandler_;
    double lambda_;
    double alpha_;
    double beta_;

private slots:
    void on_modelling_clicked();
    void on_StepByStep_clicked();

//private:
public:
    Ui::MainWindow *ui;
    StepWindow *stepWindow;
    RunWindow *runWindow;

//    int numSources_;
//    int numApplication_;
//    int numBufer_;
//    int numHandler_;
//    double lambda_;
//    double alpha_;
//    double beta_;
};
#endif // MAINWINDOW_H
