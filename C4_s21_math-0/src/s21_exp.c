#include "s21_math.h"

long double s21_exp(double x) {
  long double res = 1.0;
  long double temp = 1.0;
  if (x == s21_INFINITY) {
    res = x;
  } else if (x == -s21_INFINITY) {
    res = 0.0;
  } else if (x != x) {
    res = x;
  } else if (x > 709) {
    res = s21_INFINITY;
  } else if (x < -709) {
    res = 0;
  } else if (x > 0) {
    for (long double i = 1.0; temp > s21_EPS; i++) {
      temp *= x / i;
      res += temp;
    }
  } else if (x == 0) {
    res = 1;
  } else if (x < 0) {
    x = -x;
    for (long double i = 1.0; temp > s21_EPS; i++) {
      temp *= x / i;
      res += temp;
    }
    res = 1 / res;
  }
  return res;
}
