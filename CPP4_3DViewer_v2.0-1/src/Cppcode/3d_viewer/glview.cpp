#include "glview.h"

glview::glview(QWidget* parent) : QOpenGLWidget(parent) {
  rotation[0] = 0;
  rotation[1] = 0;
  rotation[2] = 0;
  move[0] = 0;
  move[1] = 0;
  move[2] = 0;
  scale = 1;
  type_vert = 1;
  type_lines = 1;
  size_vert = 1;
  size_lines = 1;
  projection = 0;
  size_ax_max = 1;
  color_vert.setRedF(1.0f);
  color_vert.setGreenF(1.0f);
  color_vert.setBlueF(1.0f);
  color_lines.setRedF(1.0f);
  color_lines.setGreenF(1.0f);
  color_lines.setBlueF(1.0f);
  color_back.setRedF(0.0f);
  color_back.setGreenF(0.0f);
  color_back.setBlueF(0.0f);
}

glview::~glview() {}

void glview::defineSize() {
  double size_max = fabs(info.v->all_coord[0]);
  for (int i = 0; i < info.v->amount_coord * 3; i++) {
    if (size_max < fabs(info.v->all_coord[i])) {
      size_max = fabs(info.v->all_coord[i]);
    }
  }
  size_ax_max = size_max;
}

void glview::openFile() {
  const char* file_name;
  QByteArray str = filePath.toLocal8Bit();
  file_name = str.constData();
  num_of_vert = 0;
  num_of_lines = 0;
  if (!filePath.isEmpty()) {
    s21_free_struct(&info);  // РАБОТАЕТ
    s21_initial_struct(&info);
    s21_get_input(&info, (char*)file_name);
    num_of_vert = info.v->amount_coord;
    num_of_lines = info.p->amount_edges;
    s21_centering(&info);
    //      s21_down_to_window(&info);
    defineSize();
  }
}

void glview::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH);
}

void gluPerspective( GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar )
{
    const GLdouble pi = 3.1415926535897932384626433832795;
    GLdouble fW, fH;

    //fH = tan( (fovY / 2) / 180 * pi ) * zNear;
    fH = tan( fovY / 360 * pi ) * zNear;
    fW = fH * aspect;

    glFrustum( -fW, fW, -fH, fH, zNear, zFar );
}

void glview::settingProjection() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (projection == 1) {
    gluPerspective(90.0, size_w / size_hor, 0.0001, 8 * size_ax_max);
  } else {
    glOrtho(-2 * size_ax_max, 2 * size_ax_max, -2 * size_ax_max,
            2 * size_ax_max, 0.0001, 8 * size_ax_max);
  }
  glTranslated(0.0, 0.0, -3 * size_ax_max);
}

void glview::resizeGL(int width, int height) {
  size_w = width;
  size_hor = height;
  glViewport(0, 0, height, width);
}

void glview::paintGL() {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClearColor(color_back.redF(), color_back.greenF(), color_back.blueF(),
               1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  settingProjection();
  if (!filePath.isEmpty()) {
    glEnableVertexAttribArray(0);
    glEnableClientState(GL_VERTEX_ARRAY);

    //    s21_turn(&info, rotation[0], rotation[1], rotation[2]);
    //    s21_move(&info, move[0], move[1], move[2]);
    s21_scaling(&info, scale);

    displayVertices();
    displayLines();

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableVertexAttribArray(0);
  }
}

void glview::displayVertices() {
  if (type_vert == SMOOTH) {
    glDisable(GL_POINT_SPRITE);
    glEnable(GL_POINT_SMOOTH);
  } else if (type_vert == SPRITE) {
    glDisable(GL_POINT_SMOOTH);
    glEnable(GL_POINT_SPRITE);
  }
  if (type_vert != NONE) {
    glColor3f(color_vert.redF(), color_vert.greenF(), color_vert.blueF());
    glPointSize(size_vert);
    glVertexPointer(3, GL_DOUBLE, 0, info.v->all_coord);
    glDrawArrays(GL_POINTS, 0, info.v->amount_coord);
  }
}

void glview::displayLines() {
  if (type_lines == DASHED) {
    glLineStipple(3, 0x00FF);
    glEnable(GL_LINE_STIPPLE);
  } else {
    glDisable(GL_LINE_STIPPLE);
  }
  if (type_lines != NONE) {
    glColor3f(color_lines.redF(), color_lines.greenF(), color_lines.blueF());
    glLineWidth(size_lines);
    glDrawElements(GL_LINE_LOOP, (*info.amount_polygon) * info.p->amount_p * 2,
                   GL_UNSIGNED_INT, info.p->all_p);
  }
}

void glview::mousePressEvent(QMouseEvent* mousePressed) {
  mousePosition = mousePressed->pos();
}

void glview::mouseMoveEvent(QMouseEvent* mouseEvent) {
  double yrot =
      -5e-5 * 180 / M_PI * (mouseEvent->pos().x() - mousePosition.x());
  double xrot =
      -5e-5 * 180 / M_PI * (mouseEvent->pos().y() - mousePosition.y());
  mousePosition = mouseEvent->pos();
  s21_turn(&info, xrot, yrot, 0);
  update();
}
