#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double res;
  if (exp == 0 && base != s21_NAN) {
    res = 1.0;
  } else if (base == -s21_INFINITY && exp < 0) {
    res = 0.0;
  } else if (base == -s21_INFINITY && exp > 0) {
    if (exp == (int)exp && (int)exp % 2 == 1) {
      res = -s21_INFINITY;
    } else {
      res = s21_INFINITY;
    }
  } else if (base == -1 && (exp == s21_INFINITY || exp == -s21_INFINITY)) {
    res = 1.0;
  } else if (base > -1 && base < 1 && exp == -s21_INFINITY) {
    res = s21_INFINITY;
  } else if (base > -1 && base < 1 && exp == s21_INFINITY) {
    res = 0.0;
  } else if ((base < -1 || base > 1) && exp == -s21_INFINITY) {
    res = 0.0;
  } else if ((base < -1 || base > 1) && exp == s21_INFINITY) {
    res = s21_INFINITY;
  } else if (base < 0 && exp != (int)exp) {
    res = -s21_NAN;
  } else if (base == 0 && exp < 0) {
    res = s21_INFINITY;
  } else if (base == 0 && exp > 0) {
    res = 0.0;
  } else if (base == 1 && exp != s21_NAN) {
    res = 1.0;
  } else if (base == s21_INFINITY && exp < 0) {
    res = 0.0;
  } else if (base == s21_INFINITY && exp > 0) {
    res = s21_INFINITY;
  } else {
    int negBase = 0;
    if (base < 0) {
      base = s21_fabs(base);
      if (s21_fmod(exp, 2) != 0) {
        negBase = 1;
      }
    }
    res = s21_exp(exp * s21_log(base));
    if (negBase) {
      res = -res;
    }
  }
  return res;
}
