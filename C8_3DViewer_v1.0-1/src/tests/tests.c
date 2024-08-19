#define _GNU_SOURCE
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthreads.h>

#include "../s21_Ccode/s21_3dviewer.h"

START_TEST(s21_changesize_test_1) {
//   viewer buf;
//   initial_struct(&buf);
//   free_struct(&buf);
//   struct vertex v;
//   buf.v = &v;
//   buf.v->amount_coord = 1;
//   ck_assert_int_eq(buf.v->amount_coord, 1);
//   ck_assert_double_eq_tol(result, 11.0, 7);
}
END_TEST

Suite *s21_string_suite(void) {
  Suite *suite;
  suite = suite_create("s21_3dviewer");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, s21_changesize_test_1);

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
