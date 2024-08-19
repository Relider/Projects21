#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error_num =
      s21_error_uncorrect(A, A, result) ? 1 : s21_error_compare_calc(A);
  if (!error_num) {
    matrix_t minor;
    s21_create_matrix(A->rows, A->columns, result);
    s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        double minor_znach = 0;
        create_minor(i, j, A, &minor);
        s21_determinant(&minor, &minor_znach);
        minor_znach *= pow(-1, i + j);
        result->matrix[i][j] = minor_znach;
      }
    }
    s21_remove_matrix(&minor);
  }
  return error_num;
}
