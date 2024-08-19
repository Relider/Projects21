#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int error_num = s21_error_uncorrect(A, A, A)
                      ? 1
                      : s21_error_compare_determinant(A, result);
  if (!error_num) {
    *result = 0;
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else if (A->rows == 2) {
      *result = A->matrix[0][0] * A->matrix[1][1];
      *result -= A->matrix[0][1] * A->matrix[1][0];
    } else {
      for (int i = 0; i < A->columns; i++) {
        matrix_t minor;
        double opred = 0;
        s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        create_minor(0, i, A, &minor);
        s21_determinant(&minor, &opred);
        s21_remove_matrix(&minor);
        *result += opred * A->matrix[0][i] * pow(-1, i);
      }
    }
  }
  return error_num;
}
