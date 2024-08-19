#include "s21_matrix.h"

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
