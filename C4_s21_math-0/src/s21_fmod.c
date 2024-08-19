#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res;
  if (y != 0) {
    if (x == s21_INFINITY) {
      res = s21_NAN;
    } else if (x != x || y != y) {
      res = s21_NAN;
    } else {
      int z = 1;  // положительное или отрицательное число
      if (x < 0) {
        x = -x;
        z = -1;
      }
      y = s21_fabs(y);
      while (x >= y) x -= y;
      res = x * z;
    }
  } else {
    res = s21_NAN;
  }
  return res;
}
