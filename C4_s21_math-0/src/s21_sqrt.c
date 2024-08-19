#include <math.h>

#include "s21_math.h"
#define S21_PI 3.14159265358979324
#define S21_NAN 0.0 / 0.0
#define S21_INF 1.0 / 0.0
#define S21_ln10 2.30258509299404590109
#define S21_MAX_double 1.7976931348623158e308
#define S21_NMAX 10000
#define s21_DBL_EPSILON \
  2.2e-16  // машинный ноль для double. Лежит в DBL_EPSILON, но как 2^-52. Сие
           // представление более удобно
#define s21_DBL_MAX \
  1.7976931348623158e308  // максимально возможное числоб лежит в DBL_MAX в виде
                          // 2^1024. Взято с точностью до 16 знаков
#define s21_INF 1.0 / 0.0  // для вывода бесконечночти
#define s21_NAN 0.0 / 0.0
#define s21_M_E 2.7182818284590452354
#define s21_M_LN2 0.69314718055994530942
#define s21_M_LN10 2.30258509299404568402

long double s21_sqrt(double x) {
  long double res = 0;
  int flag = 1;
  if (x >= S21_MAX_double) {
    res = S21_INF;
    flag = 0;
  }
  if (x <= -S21_MAX_double) {
    res = -S21_INF;
    flag = 0;
  }
  if (x < 0) {
    res = S21_NAN;
    flag = 0;
  }
  if (x == 0) {
    res = 0;
    flag = 0;
  }
  if (flag) {
    double a = 0, b = x;
    if (x < 1) {
      a = x;
      b = 1;
    }
    int n = 0;
    while ((fabs(b - a) > s21_EPS) && (n++ < S21_NMAX)) {
      if ((a + b) * (a + b) / 4 >= x) {
        b = (a + b) / 2;
      } else {
        a = (a + b) / 2;
      }
    }
    res = (a + b) / 2;
  }
  return res;
}
