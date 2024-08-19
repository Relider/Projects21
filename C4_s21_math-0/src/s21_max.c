#include "s21_math.h"

long double s21_max(long double x, long double y) {
  long double res = (x > y) ? x : y;
  return res;
}
