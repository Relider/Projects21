#include "s21_math.h"

long double s21_cos(double x) {
  long double step = 1, sum = 1;
  if (s21_isnan(x) || x == s21_INFINITY || x == -s21_INFINITY) {
    sum = s21_NAN;
  } else if (s21_fabs(x) < s21_EPS) {
    sum = 1.0;
  } else {
    x = s21_fmod(x, 2 * s21_M_PI);
    for (int k = 1; s21_fabs(step) > s21_EPS; k++) {
      step *= ((-1.0) * x * x) / ((2 * k - 1) * 2 * k);
      sum += step;
    }
  }
  return sum;
}
