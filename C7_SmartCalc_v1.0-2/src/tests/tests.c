#define _GNU_SOURCE
#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../SmartCalc/s21_SmartCalc.h"

START_TEST(s21_SmartCalc_test_1) {
  char *string = "2 + 2 * 5 - 1";
  double result;
  int error = s21_SmartCalc(string, 0, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, 11.0, 7);
}
END_TEST

START_TEST(s21_SmartCalc_test_2) {
  char *string = "(2 + e ^ 1) / (5 - 1)";
  double result;
  int error = s21_SmartCalc(string, 0, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, 1.1795705, 7);
}
END_TEST

START_TEST(s21_SmartCalc_test_3) {
  char *string = "(-(2 + 2) * 5) - 1 + sin(pi)";
  double result;
  int error = s21_SmartCalc(string, 0, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, -21.0, 7);
}
END_TEST

START_TEST(s21_SmartCalc_test_4) {
  char *string = "-2 + (+2) * 5 - sqrt(9) mod 10";
  double result;
  int error = s21_SmartCalc(string, 0, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, 5.0, 7);
}
END_TEST

START_TEST(s21_SmartCalc_test_5) {
  char *string = "sin(1+3) - cos(1*2) + tan(0)";
  double result;
  int error = s21_SmartCalc(string, 0, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, -0.340656, 7);
}
END_TEST

START_TEST(s21_SmartCalc_test_6) {
  char *string = "atan(5)+acos(0)+asin(0.25)";
  double result;
  int error = s21_SmartCalc(string, 0, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, 3.1492942, 7);
}
END_TEST

START_TEST(s21_SmartCalc_test_7) {
  char *string = "ln(12) - log(120)";
  double result;
  int error = s21_SmartCalc(string, 0, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, 0.4057254, 7);
}
END_TEST

START_TEST(s21_SmartCalc_test_8) {
  char *string = "0.0000001+0.0000001";
  double result;
  int error = s21_SmartCalc(string, 0, &result);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq_tol(result, 0.0000002, 7);
}
END_TEST

START_TEST(s21_SmartCalc_test_9) {
  char *string = "0.04+2+";
  double result;
  int error = s21_SmartCalc(string, 0, &result);
  ck_assert_int_ne(error, 0);
}
END_TEST

START_TEST(s21_SmartCalc_test_10) {
  char *string = "0.04+*2";
  double result;
  int error = s21_SmartCalc(string, 0, &result);
  ck_assert_int_ne(error, 0);
}
END_TEST

START_TEST(s21_SmartCalc_test_11) {
  char *string = "0.04 + 2 x";
  double result;
  int error = s21_SmartCalc(string, 0, &result);
  ck_assert_int_ne(error, 0);
}
END_TEST

START_TEST(s21_SmartCalc_test_12) {
  char *string = "3 qdf 4 + 2";
  double result;
  int error = s21_SmartCalc(string, 0, &result);
  ck_assert_int_ne(error, 0);
}
END_TEST

START_TEST(s21_SmartCalc_test_13) {
  char *string = "3,2 + 1";
  double result;
  int error = s21_SmartCalc(string, 0, &result);
  ck_assert_int_ne(error, 0);
}
END_TEST

Suite *s21_string_suite(void) {
  Suite *suite;
  suite = suite_create("s21_SmartCalc");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, s21_SmartCalc_test_1);
  tcase_add_test(tcase_core, s21_SmartCalc_test_2);
  tcase_add_test(tcase_core, s21_SmartCalc_test_3);
  tcase_add_test(tcase_core, s21_SmartCalc_test_4);
  tcase_add_test(tcase_core, s21_SmartCalc_test_5);
  tcase_add_test(tcase_core, s21_SmartCalc_test_6);
  tcase_add_test(tcase_core, s21_SmartCalc_test_7);
  tcase_add_test(tcase_core, s21_SmartCalc_test_8);
  tcase_add_test(tcase_core, s21_SmartCalc_test_9);
  tcase_add_test(tcase_core, s21_SmartCalc_test_10);
  tcase_add_test(tcase_core, s21_SmartCalc_test_11);
  tcase_add_test(tcase_core, s21_SmartCalc_test_12);
  tcase_add_test(tcase_core, s21_SmartCalc_test_13);

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
