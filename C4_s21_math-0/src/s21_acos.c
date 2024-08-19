#include "s21_math.h"

long double s21_acos(double x) {
  long double res;
  if (s21_isnan(x) || s21_fabs(x) > 1) {
    res = s21_NAN;
  } else {
    res = s21_M_PI_2 - s21_asin(x);
  }
  return res;
}
