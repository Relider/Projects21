#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define GL_SILENCE_DEPRECATION

#include <QColorDialog>
#include <QCoreApplication>
#include <QDesktopServices>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QPainter>
#include <QSettings>
#include <QString>
#include <QTime>

#include "glview.h"
extern "C" {
#include "../../Ccode/s21_3dviewer.h"
}

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
  void on_open_file_button_clicked();
  void color_vert_button_clicked();
  void color_lines_button_clicked();
  void color_back_button_clicked();
  void rotation_value_changed_X(double value);
  void rotation_value_changed_Y(double value);
  void rotation_value_changed_Z(double value);
  void translation_value_changed_X(double value);
  void translation_value_changed_Y(double value);
  void translation_value_changed_Z(double value);
  void scale_value_changed(int value);
  void vert_type_activated(int value);
  void lines_type_activated(int value);
  void size_vert_changed(int value);
  void size_lines_changed(int value);
  void projection_type_activated(int value);
  void on_screenshot_button_clicked();
  void on_gif_button_clicked();

  void saveSettings();
  void loadSettings();

 private:
  Ui::MainWindow *ui;
  QSettings *settings;
};
#endif  // MAINWINDOW_H
