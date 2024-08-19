#include "s21_3dviewer.h"

void initial_struct(viewer *head) {
  struct vertex *v = calloc(1, sizeof(struct vertex));
  struct polygon *p = calloc(2000, sizeof(struct polygon));
  struct points *coord = calloc(25000, sizeof(struct points));
  int *pol = calloc(100, sizeof(int));
  p->p = pol;
  v->coord = coord;
  head->v = v;
  head->p = p;
}

int is_border(viewer *head){
  int result = 0;
  if((head->v->amount_coord % 25000) % 10 == 0){
    result = 1;
  }
  return result;
}

void push_coord(viewer *head, double x, double y, double z) {
  if(is_border(head)){
    head->v->coord = realloc(head->v->coord, head->v->amount_coord * 10 * sizeof(struct points));
  }
  head->v->coord[head->v->amount_coord].x = x;
  head->v->coord[head->v->amount_coord].y = y;
  head->v->coord[head->v->amount_coord].z = z;
  head->v->amount_coord += 1;
}

void free_struct(viewer *head) {
  free(head->v->coord);
  free(head->v);
  free(head->p);
}
