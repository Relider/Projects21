#define _GNU_SOURCE
#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../Ccode/s21_3dviewer.h"

START_TEST(s21_3dViewer_test_1) {
  viewer buf;
  s21_initial_struct(&buf);
  int error = 1;
  ck_assert_int_eq(error, 1);
  s21_free_struct(&buf);
}
END_TEST

START_TEST(s21_3dViewer_test_2) {
  viewer buf;
  s21_initial_struct(&buf);
  char file_path[] = "tests/cube.obj";
  int error = s21_get_input(&buf, file_path);
  ck_assert_int_eq(error, 0);
  s21_free_struct(&buf);
}
END_TEST

START_TEST(s21_3dViewer_test_3) {
  viewer buf;
  s21_initial_struct(&buf);
  char file_path[] = "tests/cube.obj";
  int error = s21_get_input(&buf, file_path);
  error += s21_move(&buf, 1, 0, 0);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq(buf.v->coord[0].x, 1);
  ck_assert_double_eq(buf.v->coord[0].y, 0);
  ck_assert_double_eq(buf.v->coord[0].z, 0);
  ck_assert_double_eq(buf.v->coord[2].x, 2);
  ck_assert_double_eq(buf.v->coord[2].y, 1);
  ck_assert_double_eq(buf.v->coord[2].z, 0);
  s21_free_struct(&buf);
}
END_TEST

START_TEST(s21_3dViewer_test_4) {
  viewer buf;
  s21_initial_struct(&buf);
  char file_path[] = "tests/cube.obj";
  int error = s21_get_input(&buf, file_path);
  error += s21_move(&buf, 0, 1, 0);
  ck_assert_double_eq(buf.v->coord[0].x, 0);
  ck_assert_double_eq(buf.v->coord[0].y, 1);
  ck_assert_double_eq(buf.v->coord[0].z, 0);
  ck_assert_double_eq(buf.v->coord[2].x, 1);
  ck_assert_double_eq(buf.v->coord[2].y, 2);
  ck_assert_double_eq(buf.v->coord[2].z, 0);
  ck_assert_int_eq(error, 0);
  s21_free_struct(&buf);
}
END_TEST

START_TEST(s21_3dViewer_test_5) {
  viewer buf;
  s21_initial_struct(&buf);
  char file_path[] = "tests/cube.obj";
  int error = s21_get_input(&buf, file_path);
  error += s21_centering(&buf);
  ck_assert_int_eq(error, 0);
  ck_assert_double_eq(buf.v->coord[0].x, -0.5);
  ck_assert_double_eq(buf.v->coord[0].y, -0.5);
  ck_assert_double_eq(buf.v->coord[2].x, 0.5);
  ck_assert_double_eq(buf.v->coord[2].y, 0.5);
  s21_free_struct(&buf);
}
END_TEST

START_TEST(s21_3dViewer_test_6) {
  viewer buf;
  s21_initial_struct(&buf);
  char file_path[] = "tests/cube.obj";
  int error = s21_get_input(&buf, file_path);
  error += s21_turn(&buf, 3.14159265358, 0, 0);
  ck_assert_double_eq(buf.v->coord[0].x, 0);
  ck_assert_double_eq(buf.v->coord[0].y, 0);
  ck_assert_double_eq(buf.v->coord[0].z, 0);
  ck_assert_double_eq(buf.v->coord[2].x, 1);
  ck_assert_double_eq(buf.v->coord[2].y, -1);
  ck_assert_double_eq(buf.v->coord[4].z, -1);
  ck_assert_int_eq(error, 0);
  s21_free_struct(&buf);
}
END_TEST

START_TEST(s21_3dViewer_test_7) {
  viewer buf;
  s21_initial_struct(&buf);
  char file_path[] = "tests/cube.obj";
  int error = s21_get_input(&buf, file_path);
  error += s21_centering(&buf);
  error += s21_down_to_window(&buf);
  ck_assert_double_eq(buf.v->coord[0].x, -1);
  ck_assert_double_eq(buf.v->coord[0].y, -1);
  ck_assert_double_eq(buf.v->coord[0].z, -1);
  ck_assert_double_eq(buf.v->coord[2].x, 1);
  ck_assert_double_eq(buf.v->coord[2].y, 1);
  ck_assert_double_eq(buf.v->coord[2].z, -1);
  ck_assert_int_eq(error, 0);
  s21_free_struct(&buf);
}
END_TEST

START_TEST(s21_3dViewer_test_8) {
  viewer buf;
  s21_initial_struct(&buf);
  char file_path[] = "tests/cube.obj";
  int error = s21_get_input(&buf, file_path);
  error += s21_scaling(&buf, 3);
  ck_assert_int_eq(error, 0);
  s21_free_struct(&buf);
}
END_TEST

Suite *s21_string_suite(void) {
  Suite *suite;
  suite = suite_create("s21_3dViewer");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, s21_3dViewer_test_1);
  tcase_add_test(tcase_core, s21_3dViewer_test_2);
  tcase_add_test(tcase_core, s21_3dViewer_test_3);
  tcase_add_test(tcase_core, s21_3dViewer_test_4);
  tcase_add_test(tcase_core, s21_3dViewer_test_5);
  tcase_add_test(tcase_core, s21_3dViewer_test_6);
  tcase_add_test(tcase_core, s21_3dViewer_test_7);
  tcase_add_test(tcase_core, s21_3dViewer_test_8);

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
