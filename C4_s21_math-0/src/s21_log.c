#include "s21_math.h"

long double s21_log(double x) {
  long double res = 0.0;
  int intLog = 0;
  if (x == -s21_INFINITY || x < 0) {
    res = -s21_NAN;
  } else if (x == 0) {
    res = -s21_INFINITY;
  } else if (x == s21_INFINITY) {
    res = x;
  } else {
    for (; x >= s21_E; intLog++) x /= s21_E;
    for (int i = 0; i < 1000; i++) {
      res += 2 * (x - s21_exp(res)) / (x + s21_exp(res));
    }
    res += intLog;
  }
  return res;
}
