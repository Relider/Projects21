#include "s21_matrix.h"

void create_minor(int row, int column, matrix_t *A, matrix_t *result) {
  if (A->columns > 1 && A->rows > 1) {
    int k = 0, l = 0;
    for (int i = 0; i < A->rows; i++) {
      if (i == row) {
        continue;
      }
      for (int j = 0; j < A->columns; j++) {
        if (j == column) {
          continue;
        }
        result->matrix[k][l++] = A->matrix[i][j];
      }
      k++;
      l = 0;
    }
  }
}
