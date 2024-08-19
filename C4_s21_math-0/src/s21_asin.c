#include "s21_math.h"

long double s21_asin(double x) {
  long double sum;
  if (s21_isnan(x) || s21_fabs(x) > 1) {
    sum = s21_NAN;
  } else if (x == 1) {
    sum = s21_M_PI_2;
  } else if (x == -1) {
    sum = -s21_M_PI_2;
  } else {
    long double step = x;
    sum = x;
    for (int k = 2; s21_fabs(step) > s21_EPS / 2; k += 2) {
      step *= x * x * (k - 1) / k;
      sum += step / (k + 1);
    }
  }
  return sum;
}
