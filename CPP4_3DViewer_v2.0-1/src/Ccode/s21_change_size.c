#include "s21_3dviewer.h"

void find_centr(double *MinMax, double *center) {
  double min, max;
  min = MinMax[0];
  max = MinMax[1];
  *center = min + (max - min) / 2;
  MinMax[0] -= *center;
  MinMax[1] -= *center;
}

int s21_centering(viewer *head) {
  double centerX, centerY, centerZ;
  find_centr(head->v->MinMaxX, &centerX);
  find_centr(head->v->MinMaxY, &centerY);
  find_centr(head->v->MinMaxZ, &centerZ);
  for (int i = 0; i < head->v->amount_coord; i++) {
    head->v->coord[i].x -= centerX;
    head->v->coord[i].y -= centerY;
    head->v->coord[i].z -= centerZ;
  }
  upd_all_coord(head);
  return 0;
}

double find_max(double x, double y, double z) {
  double max_num = x;
  if (max_num < y) {
    max_num = y;
  }
  if (max_num < z) {
    max_num = z;
  }
  return max_num;
}

void scale_coord(viewer *head, double scale) {
  for (int i = 0; i < head->v->amount_coord; i++) {
    head->v->coord[i].x *= scale;
    head->v->coord[i].y *= scale;
    head->v->coord[i].z *= scale;
  }
  for (int i = 0; i <= 1; i++) {
    head->v->MinMaxX[i] *= scale;
    head->v->MinMaxY[i] *= scale;
    head->v->MinMaxZ[i] *= scale;
  }
}

int s21_down_to_window(viewer *buf) {
  double x, y, z;
  x = buf->v->MinMaxX[1] - buf->v->MinMaxX[0];
  y = buf->v->MinMaxY[1] - buf->v->MinMaxY[0];
  z = buf->v->MinMaxZ[1] - buf->v->MinMaxZ[0];
  double clmax = find_max(x, y, z);
  double scale = 2 / clmax;
  if (scale != 0) {
    scale_coord(buf, scale);
  }
  upd_all_coord(buf);
  return 0;
}
