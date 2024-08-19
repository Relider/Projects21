#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error_num =
      s21_error_uncorrect(A, A, result) ? 1 : s21_error_compare_inv(A);
  if (!error_num) {
    matrix_t buf_1, buf_2;
    if (!error_num) {
      error_num = s21_calc_complements(A, &buf_1);
    }
    if (!error_num) {
      error_num = s21_transpose(&buf_1, &buf_2);
    }
    double opred = 0;
    if (!error_num) {
      error_num = s21_determinant(A, &opred);
    }
    if (!error_num) {
      error_num = s21_create_matrix(A->rows, A->rows, result);
    }
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->rows; j++)
        result->matrix[i][j] = buf_2.matrix[i][j] / opred;
    s21_remove_matrix(&buf_1);
    s21_remove_matrix(&buf_2);
  }
  return error_num;
}
