#ifndef S21_3DVIEWER_H
#define S21_3DVIEWER_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

typedef struct {
  struct vertex *v;
  struct polygon *p;
  int *amount_polygon;
} viewer;

struct vertex {
  int amount_coord;
  struct points *coord;
  double *all_coord;
  double MinMaxX[2];
  double MinMaxY[2];
  double MinMaxZ[2];
};

struct points {
  double x;
  double y;
  double z;
};

struct polygon {
  int *p;
  int *all_p;
  int amount_p;
  int amount_edges;
};

int v_parser(viewer *head, char *input, int *count_all_coord);
int f_parser(viewer *head, char *input);
void out_of_char(char **input, int i);
int readline(FILE *file, char **input);

int is_border(int amount);
void init_min_max(viewer *head, double x, double y, double z);
void change_min_max(viewer *head, double x, double y, double z);
void out_of_coord(viewer *head, int amount_coord);
void push_coord(viewer *head, double x, double y, double z);
void out_of_polygon(viewer *head, int amount_polygon, int amount_p);
void out_of_p(viewer *head, int amount_polygon, int amount_p);
void push_polygon(viewer *head, int p);
double find_max(double x, double y, double z);
void scale_coord(viewer *head, double scale);

void s21_initial_struct(viewer *head);
void s21_free_struct(viewer *head);
int s21_get_input(viewer *head, char *path);

int s21_centering(viewer *buf);
int s21_down_to_window(viewer *buf);

void clean_matrix(matrix_t *A);
void init_matrix_move(matrix_t *A, double x, double y, double z);
void init_turn_x(matrix_t *A, double x);
void init_turn_y(matrix_t *A, double y);
void init_turn_z(matrix_t *A, double z);
void init_coords(matrix_t *B, viewer *head, int i);
void push_matrix(matrix_t *result, viewer *head, int i);
void push_minmax_move(matrix_t *result, viewer *head);
int matrix_operation(viewer *head, matrix_t *A);
int s21_move(viewer *head, double x, double y, double z);
int s21_turn(viewer *head, double x, double y, double z);
int error_val(int rows, int columns, matrix_t *result);
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_error_uncorrect(matrix_t *A, matrix_t *B, matrix_t *C);

void push_in_all_coord(viewer *head, int *count_all_coord);
void upd_all_coord(viewer *head);
int s21_scaling(viewer *head, double scale);
void push_in_all_p(viewer *head);

#endif  // S21_3DVIEWER_H
