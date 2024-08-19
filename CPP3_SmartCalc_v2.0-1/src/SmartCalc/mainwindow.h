#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <graph.h>
#include "s21_Model.h"
#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void NumPressed();
  void MathButtonPressed();
  void TrigButtonPressed();

  void on_Button_Dot_clicked();

  void on_Button_Clear_clicked();

  void on_Button_Delet_clicked();

  void on_Button_Equal_clicked();

  void on_Button_PlotGraph_clicked();

 private:
  Ui::MainWindow *ui;
  Graph *sWindow;
  Controll controll;
};

#endif  // MAINWINDOW_H
