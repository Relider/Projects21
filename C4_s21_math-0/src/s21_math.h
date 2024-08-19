#ifndef C4_S21_MATH_1_SRC_S21_MATH_H_
#define C4_S21_MATH_1_SRC_S21_MATH_H_

#include <stdio.h>
#include <stdlib.h>

#define s21_M_PI 3.14159265358979323846
#define s21_M_PI_2 1.57079632679489661923
#define s21_M_PI_4 0.785398163397448309616
#define s21_NAN 0.0 / 0.0
#define s21_INFINITY 1.0 / 0.0
#define s21_EPS 1e-17
#define s21_E 2.718281828459045091

int s21_abs(int x);
long double s21_ceil(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sqrt(double x);
long double s21_max(long double x, long double y);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);

int s21_isnan(double x);

#endif  // C4_S21_MATH_1_SRC_S21_MATH_H_
