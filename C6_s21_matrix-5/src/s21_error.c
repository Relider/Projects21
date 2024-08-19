#include "s21_matrix.h"

int s21_error_uncorrect(matrix_t *A, matrix_t *B, matrix_t *C) {
  int error_result = 0;
  if (A == NULL || B == NULL || C == NULL) {
    error_result = 1;
  }
  return error_result;
}

int s21_error_compare_sum_sub(matrix_t *A, matrix_t *B) {
  int error_result = 0;
  if (A->columns != B->columns || A->rows != B->rows || A->rows < 1 ||
      A->columns < 1) {
    error_result = 2;
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

int s21_error_compare_calc(matrix_t *A) {
  int error_result = 0;
  if (A->columns != A->rows || A->rows < 1 || A->columns < 1) {
    error_result = 2;
  }
  return error_result;
}

int s21_error_compare_determinant(matrix_t *A, double *B) {
  int error_result = 0;
  if (A->columns != A->rows || A->rows < 1 || A->columns < 1) {
    error_result = 2;
  }
  if (B == NULL) {
    error_result = 1;
  }
  return error_result;
}

int s21_error_compare_inv(matrix_t *A) {
  int error_result = 0;
  double opred = 0;
  s21_determinant(A, &opred);
  if (A->columns != A->rows || fabs(opred) < 1e-7 || A->rows < 1 ||
      A->columns < 1) {
    error_result = 2;
  }
  return error_result;
}
