#include "s21_3dviewer.h"

void s21_initial_struct(viewer *head) {
  head->amount_polygon = calloc(1000001, sizeof(int));
  head->v = calloc(1000001, sizeof(struct vertex));
  head->v->coord = calloc(100001, sizeof(struct points));
  head->p = calloc(100001, sizeof(struct polygon));
  head->p->p = calloc(100001, sizeof(int));
  head->v->all_coord = calloc(300003, sizeof(double));
  head->p->all_p = calloc(1000000000001, sizeof(int));
}

int is_border(int amount) {
  int result = 0;
  if (amount >= 100) {
    while (amount >= 10 && amount % 10 == 0) {
      amount /= 10;
    }
    result = (amount == 1) ? 1 : 0;
  }
  return result;
}

void init_min_max(viewer *head, double x, double y, double z) {
  head->v->MinMaxX[0] = x;
  head->v->MinMaxX[1] = x;
  head->v->MinMaxY[0] = y;
  head->v->MinMaxY[1] = y;
  head->v->MinMaxZ[0] = z;
  head->v->MinMaxZ[1] = z;
}

void change_min_max(viewer *head, double x, double y, double z) {
  head->v->MinMaxX[0] = (x < head->v->MinMaxX[0]) ? x : head->v->MinMaxX[0];
  head->v->MinMaxX[1] = (x > head->v->MinMaxX[1]) ? x : head->v->MinMaxX[1];
  head->v->MinMaxY[0] = (y < head->v->MinMaxY[0]) ? y : head->v->MinMaxY[0];
  head->v->MinMaxY[1] = (y > head->v->MinMaxY[1]) ? y : head->v->MinMaxY[1];
  head->v->MinMaxZ[0] = (z < head->v->MinMaxZ[0]) ? z : head->v->MinMaxZ[0];
  head->v->MinMaxZ[1] = (z > head->v->MinMaxZ[1]) ? z : head->v->MinMaxZ[1];
}

void out_of_coord(viewer *head, int amount_coord) {
  if (is_border(amount_coord)) {
    head->v->coord = realloc(head->v->coord,
                             (amount_coord * 10 + 1) * sizeof(struct points));
  }
}

void push_coord(viewer *head, double x, double y, double z) {
  int amount_coord = head->v->amount_coord++;
  if (amount_coord == 0) init_min_max(head, x, y, z);
  out_of_coord(head, amount_coord);
  head->v->coord[amount_coord].x = x;
  head->v->coord[amount_coord].y = y;
  head->v->coord[amount_coord].z = z;
  change_min_max(head, x, y, z);
}

void out_of_polygon(viewer *head, int amount_polygon, int amount_p) {
  if (is_border(amount_polygon) && amount_p == 0) {
    head->p =
        realloc(head->p, (amount_polygon * 10 + 1) * sizeof(struct polygon));
  }
}

void out_of_p(viewer *head, int amount_polygon, int amount_p) {
  if (is_border(amount_p)) {
    head->p[amount_polygon].p =
        realloc(head->p[amount_polygon].p, (amount_p * 10 + 1) * sizeof(int));
  }
}

void push_polygon(viewer *head, int p) {
  int amount_polygon = *head->amount_polygon;
  int amount_p = head->p[amount_polygon].amount_p;
  out_of_polygon(head, amount_polygon, amount_p);
  if (p == 0) {
    (*head->amount_polygon)++;
    head->p[amount_polygon + 1].p = calloc(101, sizeof(int));
    head->p[amount_polygon + 1].amount_p = 0;
  } else {
    head->p[amount_polygon].amount_p++;
    out_of_p(head, amount_polygon, amount_p);
    head->p[amount_polygon].p[amount_p] = p;
  }
}

void s21_free_struct(viewer *head) {
  if (head->v != NULL) {
    free(head->v->coord);
    free(head->v->all_coord);
    free(head->v);
  }
  if (head->p != NULL) {
    for (int i = 0; i <= *head->amount_polygon; i++) {
      free(head->p[i].p);
    }
    free(head->p->all_p);
    free(head->p);
  }
  if (head->amount_polygon != NULL) {
    free(head->amount_polygon);
  }
}
