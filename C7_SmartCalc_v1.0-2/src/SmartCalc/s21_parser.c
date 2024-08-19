#include "s21_SmartCalc.h"

void num_parser(char **string, Stack **head_num, double x) {
  if (**string >= 48 && **string <= 57) {
    char str_double[256] = "";
    int i = 0;
    while ((**string >= 48 && **string <= 57) || **string == 46) {
      str_double[i++] = *((*string)++);
    }
    char *nstr = str_double;
    push(head_num, strtod(nstr, &nstr), Number);
  }
  if (strlen(*string) >= 2) {
    if ((*string)[0] == 'p' && (*string)[1] == 'i') {
      push(head_num, PI, Number);
      *string += 2;
    }
  }
  if (strlen(*string) >= 1) {
    if ((*string)[0] == 'e') {
      push(head_num, EXP, Number);
      (*string)++;
    }
  }
  if (strlen(*string) >= 1) {
    if ((*string)[0] == 'x') {
      push(head_num, x, Number);
      (*string)++;
    }
  }
}

int get_type(char operation) {
  int result = 0;
  if (operation == '+') {
    result = 3;
  }
  if (operation == '-') {
    result = 4;
  }
  if (operation == '*') {
    result = 5;
  }
  if (operation == '/') {
    result = 6;
  }
  if (operation == '^') {
    result = 8;
  }
  return result;
}

void overflow(int cur_prior, Stack **head_num, Stack **head_calc) {
  if (*head_calc != NULL) {
    if ((*head_calc)->priority >= cur_prior && (*head_calc)->priority != 5) {
      Stack *tmp;
      while ((*head_calc != NULL) && (*head_calc)->priority >= cur_prior &&
             (*head_calc)->priority != 5) {
        push(head_num, 0, (*head_calc)->type);
        tmp = pop(head_calc);
        free(tmp);
      }
    }
  }
}

int is_unar(char **string, Stack **head_num, Stack **head_calc) {
  int result = 0;
  if (*head_num == NULL) {
    result = 1;
  } else if (*head_calc != NULL && (*head_calc)->type == 18) {
    int k = 1;
    *string -= 1;
    while (**string == ' ') {
      *string -= 1;
      k++;
    }
    if (**string == '(') {
      result = 1;
    }
    *string += k;
  }
  return result;
}

void calc_parser(char **string, Stack **head_num, Stack **head_calc) {
  if (**string == '*' || **string == '/' || **string == '^') {
    int cur_prior = s21_get_priority(get_type(**string));
    overflow(cur_prior, head_num, head_calc);
    push(head_calc, 0, get_type(*(*string)++));
  }
  if (**string == '+' || **string == '-') {
    if (is_unar(string, head_num, head_calc)) {
      push(head_num, 0, 1);
    }
    int cur_prior = s21_get_priority(get_type(**string));
    overflow(cur_prior, head_num, head_calc);
    push(head_calc, 0, get_type(*(*string)++));
  }
}

void long_calc_parser(char **string, Stack **head_num, Stack **head_calc) {
  if (strlen(*string) >= 3) {
    if ((*string)[0] == 'm' && (*string)[1] == 'o' && (*string)[2] == 'd') {
      overflow(2, head_num, head_calc);
      push(head_calc, 0, 7);
      *string += 3;
    }
  }
  if (strlen(*string) >= 4 && (*string)[0] == 's') {
    if ((*string)[1] == 'q' && (*string)[2] == 'r' && (*string)[3] == 't') {
      overflow(4, head_num, head_calc);
      push(head_calc, 0, 9);
      *string += 4;
    }
  }
  if (strlen(*string) >= 3 && (*string)[0] == 'l') {
    if ((*string)[1] == 'n') {
      overflow(4, head_num, head_calc);
      push(head_calc, 0, 16);
      *string += 2;
    }
    if ((*string)[1] == 'o' && (*string)[2] == 'g') {
      overflow(4, head_num, head_calc);
      push(head_calc, 0, 17);
      *string += 3;
    }
  }
}

void trig_parser(char **string, Stack **head_num, Stack **head_calc) {
  if (strlen(*string) >= 3) {
    if ((*string)[0] == 's' && (*string)[1] == 'i' && (*string)[2] == 'n') {
      overflow(4, head_num, head_calc);
      push(head_calc, 0, 10);
      *string += 3;
    }
    if ((*string)[0] == 'c' && (*string)[1] == 'o' && (*string)[2] == 's') {
      overflow(4, head_num, head_calc);
      push(head_calc, 0, 11);
      *string += 3;
    }
    if ((*string)[0] == 't' && (*string)[1] == 'a' && (*string)[2] == 'n') {
      overflow(4, head_num, head_calc);
      push(head_calc, 0, 12);
      *string += 3;
    }
  }
}

void ltrig_parser(char **string, Stack **head_num, Stack **head_calc) {
  if (strlen(*string) >= 4 && (*string)[0] == 'a') {
    if ((*string)[1] == 's' && (*string)[2] == 'i' && (*string)[3] == 'n') {
      overflow(4, head_num, head_calc);
      push(head_calc, 0, 13);
      *string += 4;
    }
    if ((*string)[1] == 'c' && (*string)[2] == 'o' && (*string)[3] == 's') {
      overflow(4, head_num, head_calc);
      push(head_calc, 0, 14);
      *string += 4;
    }
    if ((*string)[1] == 't' && (*string)[2] == 'a' && (*string)[3] == 'n') {
      overflow(4, head_num, head_calc);
      push(head_calc, 0, 15);
      *string += 4;
    }
  }
}

void bracket_parser(char **string, Stack **head_num, Stack **head_calc) {
  if (**string == '(') {
    push(head_calc, 0, 18);
    (*string)++;
  }
  if (**string == ')') {
    Stack *tmp;
    while ((*head_calc)->type != 18) {
      push(head_num, 0, (*head_calc)->type);
      tmp = pop(head_calc);
      free(tmp);
    }
    tmp = pop(head_calc);
    free(tmp);
    (*string)++;
  }
}

void fin_parser(Stack **head_num, Stack **head_calc) {
  Stack *tmp;
  while (*head_num != NULL) {
    push(head_calc, (*head_num)->value, (*head_num)->type);
    tmp = pop(head_num);
    free(tmp);
  }
}

int s21_parser(char *string, Stack **head_num, Stack **head_calc, double x) {
  int exit_code = 0;
  while (*string != '\0' && !exit_code) {
    char *safe_poz;
    safe_poz = string;
    num_parser(&string, head_num, x);
    calc_parser(&string, head_num, head_calc);
    long_calc_parser(&string, head_num, head_calc);
    trig_parser(&string, head_num, head_calc);
    ltrig_parser(&string, head_num, head_calc);
    bracket_parser(&string, head_num, head_calc);
    if (*string == ' ') {
      string++;
    }
    if (safe_poz == string) {
      exit_code = 1;
    }
  }
  fin_parser(head_num, head_calc);
  return exit_code;
}
