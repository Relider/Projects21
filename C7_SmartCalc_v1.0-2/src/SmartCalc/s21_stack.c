#include "s21_SmartCalc.h"

#define STACK_OVERFLOW -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY -102

int s21_get_priority(int type) {
  int result = 0;
  if (type >= 3 && type <= 4) {
    result = 1;
  }
  if (type >= 5 && type <= 7) {
    result = 2;
  }
  if (type >= 8 && type <= 8) {
    result = 3;
  }
  if (type >= 9 && type <= 17) {
    result = 4;
  }
  if (type >= 18 && type <= 19) {
    result = 5;
  }
  return result;
}

void push(Stack **head, double value, type_f type) {
  Stack *tmp = malloc(sizeof(Stack));
  tmp->value = value;
  tmp->priority = s21_get_priority(type);
  tmp->type = type;
  tmp->next = *head;
  *head = tmp;
}

Stack *pop(Stack **head) {
  Stack *out;
  out = *head;
  *head = (*head)->next;
  out->next = NULL;
  return out;
}

double peek(const Stack *head) { return head->value; }
