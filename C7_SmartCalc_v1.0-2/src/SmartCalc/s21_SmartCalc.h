#ifndef S21_SMARTCALC_H
#define S21_SMARTCALC_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXP 2.71828182845904523536
#define PI 3.14159265358979323846

typedef enum type_f {
  Number = 1,
  X = 2,
  Plus = 3,
  Minus = 4,
  Mul = 5,
  Div = 6,
  Mod = 7,
  Degree = 8,
  Sqrt = 9,
  Sin = 10,
  Cos = 11,
  Tan = 12,
  Asin = 13,
  Acos = 14,
  Atan = 15,
  Ln = 16,
  Log = 17,
  LeftBracket = 18,
  RightBracket = 19
} type_f;

typedef struct Stack {
  double value;
  int priority;
  type_f type;
  struct Stack *next;
} Stack;

void push(Stack **head, double value, type_f type);
struct Stack *pop(Stack **head);
double peek(const Stack *head);

int s21_SmartCalc(char *string, double x, double *result);
int s21_calculate(Stack **head_num, Stack **head_calc, double *result);
int s21_parser(char *string, Stack **head_out, Stack **head_calc, double x);
int s21_error_func(char *string);

int s21_get_priority(int type);

#endif  // S21_SMARTCALC_H