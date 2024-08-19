#include "graph.h"

#include <QDoubleValidator>

#include "ui_graph.h"

extern "C" int s21_SmartCalc(char *string, double x, double *result);

Graph::Graph(QWidget *parent) : QWidget(parent), ui(new Ui::Graph) {
  ui->setupUi(this);
  ui->Display->setText("");
  ui->MinX->setValidator(new QDoubleValidator(-100, 100, 2, this));
  ui->MinY->setValidator(new QDoubleValidator(-100, 100, 2, this));
  ui->MaxX->setValidator(new QDoubleValidator(-100, 100, 2, this));
  ui->MaxY->setValidator(new QDoubleValidator(-100, 100, 2, this));
  ui->MinX->setPlaceholderText("MIN");
  ui->MaxX->setPlaceholderText("MAX");
  ui->MinY->setPlaceholderText("MIN");
  ui->MaxY->setPlaceholderText("MAX");
}

Graph::~Graph() { delete ui; }

void Graph::on_PlotButton_clicked() {
  QString displayVal = ui->Display->text();
  QByteArray disp = displayVal.toLocal8Bit();
  const char *c_str = disp.data();
  int err_code = 0, n = 40000;
  QVector<double> x(n), y(n);
  for (int i = 0; i < n && !err_code; i++) {
    x[i] = -1000.0 + 0.05 * i;
    err_code = s21_SmartCalc((char *)c_str, x[i], &y[i]);
  }
  if (!err_code) {
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    QString doub_Min_x = ui->MinX->text();
    QString doub_Max_x = ui->MaxX->text();
    QString doub_Min_y = ui->MinY->text();
    QString doub_Max_y = ui->MaxY->text();
    QByteArray doubMinX = doub_Min_x.toLocal8Bit();
    QByteArray doubMaxX = doub_Max_x.toLocal8Bit();
    QByteArray doubMinY = doub_Min_y.toLocal8Bit();
    QByteArray doubMaxY = doub_Max_y.toLocal8Bit();
    const char *Min_X = doubMinX.data();
    const char *Max_X = doubMaxX.data();
    const char *Min_Y = doubMinY.data();
    const char *Max_Y = doubMaxY.data();
    double minimalX = atof((char *)Min_X), maximalX = atof((char *)Max_X);
    double minimalY = atof((char *)Min_Y), maximalY = atof((char *)Max_Y);
    //    minimalX = (minimalX < -1000000) ? -1000000 : minimalX;
    //    minimalX = (maximalX > 1000000) ? -1000000 : maximalX;
    //    minimalY = (minimalY < -1000000) ? -1000000 : minimalY;
    //    minimalY = (maximalY > 1000000) ? -1000000 : maximalY;
    ui->widget->xAxis->setRange(minimalX, maximalX);
    ui->widget->yAxis->setRange(minimalY, maximalY);
    ui->widget->replot();
  } else {
    ui->Display->setText("");
    ui->Display->setPlaceholderText("error: invalid input");
  }
}

void Graph::sendLabel(const QString &x) { ui->Display->setText(x); }
