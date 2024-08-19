#ifndef GLVIEW_H
#define GLVIEW_H
#define GL_SILENCE_DEPRECATION

#include <GL/gl.h>

#include <QMessageBox>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QWidget>

#define NONE 0
#define SMOOTH 1
#define SPRITE 2

#define DASHED 2

extern "C" {
#include "../../Ccode/s21_3dviewer.h"
}

class glview : public QOpenGLWidget, protected QOpenGLFunctions {
 public:
  glview(QWidget *parent);
  ~glview();

  void openFile();

  QString filePath;
  int num_of_vert;
  int num_of_lines;
  int size_hor = 0;
  int size_w = 0;
  double move[3];
  double rotation[3];
  double scale;
  double scale_value;
  int type_vert = 0;
  int type_lines = 0;
  int size_vert = 1;
  int size_lines = 1;
  int projection;
  double size_ax_max;
  QColor color_vert;
  QColor color_lines;
  QColor color_back;
  viewer info;

 private:
  void displayVertices();
  void displayLines();
  void defineSize();
  void settingProjection();

  void initializeGL() override;
  void resizeGL(int width, int height) override;
  void paintGL() override;

  QPoint mousePosition;
  void mouseMoveEvent(QMouseEvent *) override;
  void mousePressEvent(QMouseEvent *) override;
};

#endif  // GLVIEW_H
