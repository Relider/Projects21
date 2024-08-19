#define _GNU_SOURCE
#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"

START_TEST(s21_create_matrix_test) {
  matrix_t A;
  int err;
  err = s21_create_matrix(1, 5, &A);
  ck_assert(&A != NULL);
  ck_assert_int_eq(err, 0);
  s21_remove_matrix(&A);
  err = s21_create_matrix(5, 5, &A);
  ck_assert(&A != NULL);
  ck_assert_int_eq(err, 0);
  s21_remove_matrix(&A);
  err = s21_create_matrix(-1, 5, &A);
  ck_assert_int_eq(err, 1);
  err = s21_create_matrix(5, -1, &A);
  ck_assert_int_eq(err, 1);
  err = s21_create_matrix(5, 5, NULL);
  ck_assert_int_eq(err, 1);
  err = s21_create_matrix(0, 5, NULL);
  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(s21_remove_matrix_test) {
  matrix_t A;
  s21_create_matrix(1, 5, &A);
  s21_remove_matrix(&A);
  s21_remove_matrix(NULL);
}
END_TEST

START_TEST(s21_eq_matrix_test) {
  matrix_t A, B;
  int res;
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(1, 5, &B);

  for (int column = 0; column < 5; column++) {
    A.matrix[0][column] = column;
    B.matrix[0][column] = column;
  }
  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, SUCCESS);

  for (int column = 0; column < 5; column++) {
    A.matrix[0][column] = 1;
    B.matrix[0][column] = column;
  }
  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_create_matrix(3, 5, &A);
  s21_create_matrix(3, 5, &B);

  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 5; column++) {
      A.matrix[row][column] = column;
      B.matrix[row][column] = column;
    }
  }
  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, SUCCESS);

  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 5; column++) {
      A.matrix[row][column] = column;
      B.matrix[row][column] = 2;
    }
  }
  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_create_matrix(2, 5, &A);
  s21_create_matrix(3, 5, &B);

  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_create_matrix(2, 5, &A);
  s21_create_matrix(2, 2, &B);

  res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  res = s21_eq_matrix(NULL, NULL);
  ck_assert_int_eq(res, FAILURE);
}
END_TEST

START_TEST(s21_sum_matrix_test_1) {
  matrix_t A, B, C, result;
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(1, 5, &B);
  s21_create_matrix(1, 5, &C);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.rows; j++) {
      A.matrix[i][j] = 1;
      B.matrix[i][j] = 1;
      C.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
    }
  }
  int res = s21_sum_matrix(&A, &B, &result);
  int res_eq = s21_eq_matrix(&result, &C);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_test_2) {
  matrix_t A, B, result;
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(2, 5, &B);
  int res = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_test_4) {
  matrix_t A, result;
  s21_create_matrix(1, 5, &A);
  int res = s21_sum_matrix(&A, NULL, &result);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_sum_matrix_test_5) {
  matrix_t A, B;
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(1, 5, &B);
  int res = s21_sum_matrix(&A, &B, NULL);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_test_1) {
  matrix_t A, B, C, result;
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(1, 5, &B);
  s21_create_matrix(1, 5, &C);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.rows; j++) {
      A.matrix[i][j] = 1;
      B.matrix[i][j] = 1;
      C.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
    }
  }
  int res = s21_sub_matrix(&A, &B, &result);
  int res_eq = s21_eq_matrix(&result, &C);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_test_2) {
  matrix_t A, B, result;
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(2, 5, &B);
  int res = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_test_4) {
  matrix_t A, result;
  s21_create_matrix(1, 5, &A);
  int res = s21_sub_matrix(&A, NULL, &result);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_sub_matrix_test_5) {
  matrix_t A, B;
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(1, 5, &B);
  int res = s21_sub_matrix(&A, &B, NULL);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_number_test_1) {
  matrix_t A, C, result;
  double number = 5.5;
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(1, 5, &C);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.rows; j++) {
      A.matrix[i][j] = 1;
      C.matrix[i][j] = A.matrix[i][j] * number;
    }
  }
  int res = s21_mult_number(&A, number, &result);
  int res_eq = s21_eq_matrix(&result, &C);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_test_3) {
  matrix_t result;
  double number = 5.5;
  int res = s21_mult_number(NULL, number, &result);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_mult_number_test_4) {
  matrix_t A;
  double number = 5.5;
  s21_create_matrix(1, 5, &A);
  int res = s21_mult_number(&A, number, NULL);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_matrix_test_1) {
  matrix_t A, B, C, result;
  s21_create_matrix(3, 5, &A);
  s21_create_matrix(5, 3, &B);
  s21_create_matrix(3, 3, &C);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.rows; j++) {
      A.matrix[i][j] = 1;
      B.matrix[i][j] = 1;
      C.matrix[i][j] = 3;
    }
  }
  int res = s21_mult_matrix(&A, &B, &result);
  int res_eq = s21_eq_matrix(&result, &C);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test_2) {
  matrix_t A, B, result;
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(4, 2, &B);
  int res = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_test_4) {
  matrix_t A, result;
  s21_create_matrix(1, 5, &A);
  int res = s21_mult_matrix(&A, NULL, &result);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_matrix_test_5) {
  matrix_t A, B;
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(5, 2, &B);
  int res = s21_mult_matrix(&A, &B, NULL);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_transpose_test_1) {
  matrix_t A, C, result;
  s21_create_matrix(2, 5, &A);
  s21_create_matrix(5, 2, &C);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.rows; j++) {
      A.matrix[i][j] = i;
      C.matrix[j][i] = i;
    }
  }
  int res = s21_transpose(&A, &result);
  int res_eq = s21_eq_matrix(&result, &C);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_test_4) {
  matrix_t result;
  int res = s21_transpose(NULL, &result);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_transpose_test_5) {
  matrix_t A;
  s21_create_matrix(1, 5, &A);
  int res = s21_transpose(&A, NULL);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_1) {
  matrix_t A;
  double C = -30, result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 4;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = 4;
  A.matrix[2][1] = 4;
  A.matrix[2][2] = 1;
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(C, result);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_2) {
  matrix_t A;
  double result = 0;
  s21_create_matrix(1, 3, &A);
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_3) {
  matrix_t A;
  double result = 0;
  s21_create_matrix(3, 2, &A);
  int res = s21_determinant(&A, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_4) {
  double result = 0;
  int res = s21_determinant(NULL, &result);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_determinant_test_5) {
  matrix_t A;
  s21_create_matrix(1, 5, &A);
  int res = s21_determinant(&A, NULL);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_test_1) {
  matrix_t A, C, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  C.matrix[0][0] = 0;
  C.matrix[0][1] = 10;
  C.matrix[0][2] = -20;
  C.matrix[1][0] = 4;
  C.matrix[1][1] = -14;
  C.matrix[1][2] = 8;
  C.matrix[2][0] = -8;
  C.matrix[2][1] = -2;
  C.matrix[2][2] = 4;
  int res = s21_calc_complements(&A, &result);
  int res_eq = s21_eq_matrix(&result, &C);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_test_2) {
  matrix_t A, result;
  s21_create_matrix(2, 5, &A);
  int res = s21_calc_complements(&A, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_test_3) {
  matrix_t A, result;
  s21_create_matrix(1, 5, &A);
  int res = s21_calc_complements(&A, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_test_4) {
  matrix_t result;
  int res = s21_calc_complements(NULL, &result);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_calc_complements_test_5) {
  matrix_t A;
  s21_create_matrix(1, 5, &A);
  int res = s21_calc_complements(&A, NULL);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_test_1) {
  matrix_t A, C, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  C.matrix[0][0] = 1;
  C.matrix[0][1] = -1;
  C.matrix[0][2] = 1;
  C.matrix[1][0] = -38;
  C.matrix[1][1] = 41;
  C.matrix[1][2] = -34;
  C.matrix[2][0] = 27;
  C.matrix[2][1] = -29;
  C.matrix[2][2] = 24;
  int res = s21_inverse_matrix(&A, &result);
  int res_eq = s21_eq_matrix(&result, &C);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_eq, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_2) {
  matrix_t A, result;
  s21_create_matrix(7, 5, &A);
  int res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_test_3) {
  matrix_t A, result;
  s21_create_matrix(1, 5, &A);
  int res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_test_4) {
  matrix_t result;
  int res = s21_inverse_matrix(NULL, &result);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_inverse_matrix_test_5) {
  matrix_t A;
  s21_create_matrix(1, 5, &A);
  int res = s21_inverse_matrix(&A, NULL);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_string_suite(void) {
  Suite *suite;
  suite = suite_create("s21_matrix");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, s21_create_matrix_test);
  tcase_add_test(tcase_core, s21_remove_matrix_test);
  tcase_add_test(tcase_core, s21_eq_matrix_test);

  tcase_add_test(tcase_core, s21_sum_matrix_test_1);
  tcase_add_test(tcase_core, s21_sum_matrix_test_2);
  tcase_add_test(tcase_core, s21_sum_matrix_test_4);
  tcase_add_test(tcase_core, s21_sum_matrix_test_5);

  tcase_add_test(tcase_core, s21_sub_matrix_test_1);
  tcase_add_test(tcase_core, s21_sub_matrix_test_2);
  tcase_add_test(tcase_core, s21_sub_matrix_test_4);
  tcase_add_test(tcase_core, s21_sub_matrix_test_5);

  tcase_add_test(tcase_core, s21_mult_number_test_1);
  tcase_add_test(tcase_core, s21_mult_number_test_3);
  tcase_add_test(tcase_core, s21_mult_number_test_4);

  tcase_add_test(tcase_core, s21_mult_matrix_test_1);
  tcase_add_test(tcase_core, s21_mult_matrix_test_2);
  tcase_add_test(tcase_core, s21_mult_matrix_test_4);
  tcase_add_test(tcase_core, s21_mult_matrix_test_5);

  tcase_add_test(tcase_core, s21_transpose_test_1);
  tcase_add_test(tcase_core, s21_transpose_test_4);
  tcase_add_test(tcase_core, s21_transpose_test_5);

  tcase_add_test(tcase_core, s21_determinant_test_1);
  tcase_add_test(tcase_core, s21_determinant_test_2);
  tcase_add_test(tcase_core, s21_determinant_test_3);
  tcase_add_test(tcase_core, s21_determinant_test_4);
  tcase_add_test(tcase_core, s21_determinant_test_5);

  tcase_add_test(tcase_core, s21_calc_complements_test_1);
  tcase_add_test(tcase_core, s21_calc_complements_test_2);
  tcase_add_test(tcase_core, s21_calc_complements_test_3);
  tcase_add_test(tcase_core, s21_calc_complements_test_4);
  tcase_add_test(tcase_core, s21_calc_complements_test_5);

  tcase_add_test(tcase_core, s21_inverse_matrix_test_1);
  tcase_add_test(tcase_core, s21_inverse_matrix_test_2);
  tcase_add_test(tcase_core, s21_inverse_matrix_test_3);
  tcase_add_test(tcase_core, s21_inverse_matrix_test_4);
  tcase_add_test(tcase_core, s21_inverse_matrix_test_5);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

int main(void) {
  Suite *suite = s21_string_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
