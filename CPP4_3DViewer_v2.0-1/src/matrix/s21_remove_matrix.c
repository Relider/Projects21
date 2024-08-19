#include "s21_matrix.h"

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
