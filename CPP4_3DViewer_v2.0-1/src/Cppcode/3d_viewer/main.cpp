#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  QApplication::setOrganizationName("Sobchakr");
  QApplication::setApplicationName("s21_3dViewer");

  MainWindow w;
  w.setWindowTitle("3D Viewer");
  w.show();
  return a.exec();
}
