#include "s21_math.h"

long double s21_floor(double x) {
  long double res;
  if (s21_isnan(x) || x == s21_INFINITY || x == -s21_INFINITY || x == 0.0) {
    res = x;
  } else if (x < 0 && (x - (long long int)x != 0)) {
    res = (long long int)x - 1;
  } else {
    res = (long long int)x;
  }
  return res;
}
