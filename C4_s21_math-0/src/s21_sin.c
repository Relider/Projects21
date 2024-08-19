#include "s21_math.h"

long double s21_sin(double x) {
  long double sum;
  if (s21_isnan(x) || x == s21_INFINITY || x == -s21_INFINITY) {
    sum = s21_NAN;
  } else {
    x = s21_fmod(x, 2 * s21_M_PI);
    if (x == +0 || x == -0 || x == s21_M_PI) {
      sum = 0;
    } else if (x == s21_M_PI_2) {
      sum = 1.0;
    } else if (x == -s21_M_PI_2) {
      sum = -1.0;
    } else {
      long double step = x;
      sum = x;
      for (int k = 1; s21_fabs(step) > s21_EPS; k++) {
        step *= ((-1.0) * x * x) / ((2 * k + 1) * 2 * k);
        sum += step;
      }
    }
  }
  return sum;
}
