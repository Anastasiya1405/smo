#ifndef RUNWINDOW_H
#define RUNWINDOW_H

#include <QDialog>
#include <QTableWidget>

namespace Ui {
  class RunWindow;
}

class RunWindow : public QDialog
{
  Q_OBJECT

public:
  explicit RunWindow(QWidget *parent = 0);
  ~RunWindow();

private slots:
    void on_pushButton_clicked();

private:
  Ui::RunWindow *ui;
  int numSources_;
  int numApplication_;
  int numBufer_;
  int numHandler_;
  double lambda_;
  double alpha_;
  double beta_;

};

#endif // RUNWINDOW_H
