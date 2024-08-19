#include "s21_math.h"

int s21_isnan(double x) {
  int res = 0;
  if (x != x) {
    res = 1;
  }
  return res;
}
