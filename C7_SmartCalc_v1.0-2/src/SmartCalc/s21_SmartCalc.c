#include "s21_SmartCalc.h"

int s21_SmartCalc(char *string, double x, double *result) {
  int err_code = s21_error_func(string);
  Stack *head_num = NULL;
  Stack *head_calc = NULL;
  if (!err_code) {
    err_code = s21_parser(string, &head_num, &head_calc, x);
    err_code += s21_calculate(&head_num, &head_calc, result);
    err_code = (err_code != 0);
  }
  return err_code;
}
