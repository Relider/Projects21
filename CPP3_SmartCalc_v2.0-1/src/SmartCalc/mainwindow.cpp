#include "mainwindow.h"

#include <QDoubleValidator>

#include "graph.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  sWindow = new Graph();

  ui->DispX->setValidator(new QDoubleValidator(-100, 100, 2, this));
  ui->DispX->setPlaceholderText("x = 0");

  QPushButton *numButtons[10];
  for (int i = 0; i < 10; ++i) {
    QString butName = "Button_" + QString::number(i);
    numButtons[i] = MainWindow::findChild<QPushButton *>(butName);
    connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));
  }
  connect(ui->Button_X, SIGNAL(released()), this, SLOT(NumPressed()));
  connect(ui->Button_pi, SIGNAL(released()), this, SLOT(NumPressed()));
  connect(ui->Button_e, SIGNAL(released()), this, SLOT(NumPressed()));
  connect(ui->Button_LeftBracket, SIGNAL(released()), this, SLOT(NumPressed()));
  connect(ui->Button_RightBracket, SIGNAL(released()), this,
          SLOT(NumPressed()));

  connect(ui->Button_Add, SIGNAL(released()), this, SLOT(MathButtonPressed()));
  connect(ui->Button_Sub, SIGNAL(released()), this, SLOT(MathButtonPressed()));
  connect(ui->Button_Mul, SIGNAL(released()), this, SLOT(MathButtonPressed()));
  connect(ui->Button_Div, SIGNAL(released()), this, SLOT(MathButtonPressed()));
  connect(ui->Button_Mod, SIGNAL(released()), this, SLOT(MathButtonPressed()));
  connect(ui->Button_Degree, SIGNAL(released()), this,
          SLOT(MathButtonPressed()));

  connect(ui->Button_Cos, SIGNAL(released()), this, SLOT(TrigButtonPressed()));
  connect(ui->Button_Acos, SIGNAL(released()), this, SLOT(TrigButtonPressed()));
  connect(ui->Button_Sin, SIGNAL(released()), this, SLOT(TrigButtonPressed()));
  connect(ui->Button_Asin, SIGNAL(released()), this, SLOT(TrigButtonPressed()));
  connect(ui->Button_Tan, SIGNAL(released()), this, SLOT(TrigButtonPressed()));
  connect(ui->Button_Atan, SIGNAL(released()), this, SLOT(TrigButtonPressed()));
  connect(ui->Button_Log, SIGNAL(released()), this, SLOT(TrigButtonPressed()));
  connect(ui->Button_NatLog, SIGNAL(released()), this,
          SLOT(TrigButtonPressed()));
  connect(ui->Button_Sqrt, SIGNAL(released()), this, SLOT(TrigButtonPressed()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::NumPressed() {
  QPushButton *button = (QPushButton *)sender();
  QString butVal = button->text();
  QString displayVal = ui->Display->text();
  if ((displayVal == "0") || (displayVal == "0.0")) {
    ui->Display->setText(butVal);
  } else {
    QString newVal = displayVal + butVal;
    ui->Display->setText(newVal);
  }
}

void MainWindow::MathButtonPressed() {
  QPushButton *button = (QPushButton *)sender();
  QString butVal = button->text();
  QString displayVal = ui->Display->text();
  QString newVal = displayVal + butVal;
  if (displayVal == "0.0" && (butVal == '-' || butVal == '+')) {
    ui->Display->setText(newVal);
  } else {
    ui->Display->setText(newVal);
  }
}

void MainWindow::TrigButtonPressed() {
  QPushButton *button = (QPushButton *)sender();
  QString butVal = " " + button->text() + "(";
  QString displayVal = ui->Display->text();
  if ((displayVal == "0") || (displayVal == "0.0")) {
    ui->Display->setText(butVal);
  } else {
    QString newVal = displayVal + butVal;
    ui->Display->setText(newVal);
  }
}

void MainWindow::on_Button_Dot_clicked() {
  QString butVal = ui->Button_Dot->text();
  QString displayVal = ui->Display->text();
  if (displayVal == "0.0") {
    ui->Display->setText("0" + butVal);
  } else {
    QString newVal = displayVal + butVal;
    ui->Display->setText(newVal);
  }
}

void MainWindow::on_Button_Clear_clicked() { ui->Display->setText("0.0"); }

void MainWindow::on_Button_Delet_clicked() {
  QString displayVal = ui->Display->text();
  displayVal.chop(1);
  ui->Display->setText(displayVal);
}

void MainWindow::on_Button_Equal_clicked() {
  QString doub_x = ui->DispX->text();
  QString displayVal = ui->Display->text();
  QByteArray doub = doub_x.toLocal8Bit();
  QByteArray disp = displayVal.toLocal8Bit();
  const char *c_str1 = doub.data();
  const char *c_str2 = disp.data();
  double x = atof((char *)c_str1);
  double buf_res = 0;
  if (controll.s21_SmartCalc((char *)c_str2, x, &buf_res)) {
    ui->Display->setText("");
    ui->Display->setPlaceholderText("error: invalid input");
  } else {
    ui->Display->setText(QString::number(buf_res));
  }
}

void MainWindow::on_Button_PlotGraph_clicked() {
  sWindow->sendLabel(ui->Display->text());
  sWindow->show();
}
