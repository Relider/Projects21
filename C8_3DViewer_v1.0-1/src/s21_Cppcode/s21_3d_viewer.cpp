#include "s21_3d_viewer.h"
#include "ui_s21_3d_viewer.h"

s21_3d_viewer::s21_3d_viewer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::s21_3d_viewer)
{
    ui->setupUi(this);
}

s21_3d_viewer::~s21_3d_viewer()
{
    delete ui;
}

