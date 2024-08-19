#include "s21_Controll.h"

int Controll::expression_error(char *string) {
  int err_code = 0, i = 0;
  while (string[i] != '\0' && !err_code) {
    if (string[i] == ',') {
      err_code = 1;
    }
    i++;
  }

  return err_code;
}

int Controll::s21_error_func(char *string) {
  int code_err = 0;
  code_err = expression_error(string);
  return code_err;
}
