#include "s21_math.h"

long double s21_atan(double x) {
  long double sum;
  if (s21_isnan(x)) {
    sum = s21_NAN;
  } else if (x == s21_INFINITY) {
    sum = s21_M_PI_2;
  } else if (x == -s21_INFINITY) {
    sum = -s21_M_PI_2;
  } else if (x == 1) {
    sum = s21_M_PI_4;
  } else if (x == -1) {
    sum = -s21_M_PI_4;
  } else {
    int negX = 0;
    if (x < 0) negX = 1;
    x = s21_fabs(x);
    int ok = 0;
    if (x > 1) {
      x = 1 / x;
      ok = 1;
    }
    long double step = x;
    sum = x;
    for (int k = 2; s21_fabs(step) * 10 > s21_EPS; k++) {
      step *= -x * x;
      sum += step / (2 * k - 1);
    }
    if (ok) sum = s21_M_PI_2 - sum;
    if (negX) sum = -sum;
  }
  return sum;
}
