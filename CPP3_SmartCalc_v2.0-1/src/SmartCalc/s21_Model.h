#ifndef S21_MODEL_H
#define S21_MODEL_H

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

class Model{
private:

public:
    Model() {};
    ~Model() {};
    void push(Stack **head, double value, type_f type);
    struct Stack *pop(Stack **head);
    double peek(const Stack *head);
    int s21_get_priority(int type);
    int get_type(char operation);
    void overflow(int cur_prior, Stack **head_num, Stack **head_calc);
    int is_unar(char **string, Stack **head_num, Stack **head_calc);
};

#endif  // S21_MODEL_H
