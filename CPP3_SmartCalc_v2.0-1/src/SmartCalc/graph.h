#ifndef GRAPH_H
#define GRAPH_H

#include <qcustomplot.h>
#include "s21_Controll.h"
#include <QWidget>

namespace Ui {
class Graph;
}

class Graph : public QWidget {
  Q_OBJECT

 public:
  explicit Graph(QWidget *parent = nullptr);
  ~Graph();
  void sendLabel(const QString &x);

 private slots:
  void on_PlotButton_clicked();

 private:
  Controll controll;
  Ui::Graph *ui;
};

#endif  // GRAPH_H
