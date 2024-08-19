#include "s21_3dviewer.h"

int error_val(int rows, int columns, matrix_t *result) {
  int result_val = 0;
  if (result == NULL) {
    result_val = 1;
  }
  if ((rows <= 0) || (columns <= 0)) {
    result_val = 1;
  }
  return result_val;
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res_val = error_val(rows, columns, result);
  if (res_val == 0) {
    result->columns = columns;
    result->rows = rows;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    for (int num_row = 0; num_row < rows; num_row++) {
      result->matrix[num_row] = (double *)calloc(columns, sizeof(double));
    }
  }
  return res_val;
}
void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    if (A->matrix != NULL) {
      for (int num_row = 0; num_row < A->rows; num_row++) {
        free(A->matrix[num_row]);
      }
      free(A->matrix);
    }
  }
}

int s21_error_uncorrect(matrix_t *A, matrix_t *B, matrix_t *C) {
  int error_result = 0;
  if (A == NULL || B == NULL || C == NULL) {
    error_result = 1;
  }
  return error_result;
}

int s21_error_compare_mult(matrix_t *A, matrix_t *B) {
  int error_result = 0;
  if (A->columns != B->rows || A->rows < 1 || A->columns < 1) {
    error_result = 2;
  }
  return error_result;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_num =
      s21_error_uncorrect(A, B, result) ? 1 : s21_error_compare_mult(A, B);
  if (!error_num) {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return error_num;
}

void clean_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = 0;
    }
  }
}

void init_matrix_move(matrix_t *A, double x, double y, double z) {
  clean_matrix(A);
  A->matrix[0][0] = 1;
  A->matrix[0][3] = x;
  A->matrix[1][1] = 1;
  A->matrix[1][3] = y;
  A->matrix[2][2] = 1;
  A->matrix[2][3] = z;
  A->matrix[3][3] = 1;
}

void init_turn_x(matrix_t *A, double x) {
  clean_matrix(A);
  A->matrix[0][0] = 1;
  A->matrix[1][1] = cos(x);
  A->matrix[1][2] = sin(x);
  A->matrix[2][1] = -sin(x);
  A->matrix[2][2] = cos(x);
  A->matrix[3][3] = 1;
}

void init_turn_y(matrix_t *A, double y) {
  clean_matrix(A);
  A->matrix[0][0] = cos(y);
  A->matrix[0][2] = -sin(y);
  A->matrix[1][1] = 1;
  A->matrix[2][0] = sin(y);
  A->matrix[2][2] = cos(y);
  A->matrix[3][3] = 1;
}

void init_turn_z(matrix_t *A, double z) {
  clean_matrix(A);
  A->matrix[0][0] = cos(z);
  A->matrix[0][1] = sin(z);
  A->matrix[1][0] = -sin(z);
  A->matrix[1][1] = cos(z);
  A->matrix[2][2] = 1;
  A->matrix[3][3] = 1;
}

void init_coords(matrix_t *B, viewer *head, int i) {
  clean_matrix(B);
  B->matrix[0][0] = head->v->coord[i].x;
  B->matrix[1][0] = head->v->coord[i].y;
  B->matrix[2][0] = head->v->coord[i].z;
  B->matrix[3][0] = 1;
}

void push_matrix(matrix_t *result, viewer *head, int i) {
  head->v->coord[i].x = result->matrix[0][0];
  head->v->coord[i].y = result->matrix[1][0];
  head->v->coord[i].z = result->matrix[2][0];
}

void push_minmax_move(matrix_t *result, viewer *head) {
  head->v->MinMaxX[0] += result->matrix[0][3];
  head->v->MinMaxX[1] += result->matrix[0][3];
  head->v->MinMaxY[0] += result->matrix[1][3];
  head->v->MinMaxY[1] += result->matrix[1][3];
  head->v->MinMaxZ[0] += result->matrix[2][3];
  head->v->MinMaxZ[1] += result->matrix[2][3];
}

int matrix_operation(viewer *head, matrix_t *A) {
  int err = 0;
  matrix_t B, result;
  err += s21_create_matrix(4, 1, &B);
  for (int i = 0; i < head->v->amount_coord; i++) {
    init_coords(&B, head, i);
    err += s21_mult_matrix(A, &B, &result);
    push_matrix(&result, head, i);
    s21_remove_matrix(&result);
  }
  s21_remove_matrix(&B);
  return (err != 0);
}

void upd_all_coord(viewer *head) {
  int for_all_coord = 0, for_coord = 0;
  while (for_all_coord <= head->v->amount_coord * 3) {
    head->v->all_coord[for_all_coord] = head->v->coord[for_coord].x;
    head->v->all_coord[for_all_coord + 1] = head->v->coord[for_coord].y;
    head->v->all_coord[for_all_coord + 2] = head->v->coord[for_coord].z;
    for_coord++;
    for_all_coord += 3;
  }
}

int s21_move(viewer *head, double x, double y, double z) {
  int err = 0;
  matrix_t A;
  err += s21_create_matrix(4, 4, &A);
  init_matrix_move(&A, x, y, z);
  err += matrix_operation(head, &A);
  push_minmax_move(&A, head);
  s21_remove_matrix(&A);
  upd_all_coord(head);
  return (err != 0);
}

int s21_turn(viewer *head, double x, double y, double z) {
  int err = 1;
  if (head->p != NULL) {
    err -= 1;
    matrix_t A;
    err += s21_create_matrix(4, 4, &A);
    init_turn_x(&A, x);
    err += matrix_operation(head, &A);
    init_turn_y(&A, y);
    err += matrix_operation(head, &A);
    init_turn_z(&A, z);
    err += matrix_operation(head, &A);
    s21_remove_matrix(&A);
    upd_all_coord(head);
  }
  return (err != 0);
}

int s21_scaling(viewer *head, double scale) {
  int error = 0;
  if (scale != 0 && head->v != NULL) {
    for (int i = 0; i <= head->v->amount_coord * 3; i++) {
      head->v->all_coord[i] *= scale;
    }
  } else {
    error = 1;
  }
  return error;
}
