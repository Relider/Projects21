#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res_val = FAILURE;
  if (A != NULL && B != NULL) {
    if ((A->columns == B->columns) && (A->rows == B->rows) &&
        A->matrix != NULL && B->matrix != NULL) {
      res_val = SUCCESS;
      for (int row = 0; row < A->rows; row++) {
        for (int column = 0; column < A->columns; column++) {
          if (fabs(A->matrix[row][column] - B->matrix[row][column]) > 1e-7) {
            res_val = FAILURE;
            break;
          }
        }
        if (!res_val) {
          break;
        }
      }
    }
  }
  return res_val;
}
