#include "s21_Controll.h"
#include "s21_Model.h"

void Controll::num_parser(char **string, Stack **head_num, double x) {
  if (**string >= 48 && **string <= 57) {
    char str_double[256] = "";
    int i = 0;
    while ((**string >= 48 && **string <= 57) || **string == 46) {
      str_double[i++] = *((*string)++);
    }
    char *nstr = str_double;
    model.push(head_num, strtod(nstr, &nstr), Number);
  }
  if (strlen(*string) >= 2) {
    if ((*string)[0] == 'p' && (*string)[1] == 'i') {
      model.push(head_num, PI, Number);
      *string += 2;
    }
  }
  if (strlen(*string) >= 1) {
    if ((*string)[0] == 'e') {
      model.push(head_num, EXP, Number);
      (*string)++;
    }
  }
  if (strlen(*string) >= 1) {
    if ((*string)[0] == 'x') {
      model.push(head_num, x, Number);
      (*string)++;
    }
  }
}

int Model::get_type(char operation) {
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

void Model::overflow(int cur_prior, Stack **head_num, Stack **head_calc) {
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

int Model::is_unar(char **string, Stack **head_num, Stack **head_calc) {
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

void Controll::calc_parser(char **string, Stack **head_num, Stack **head_calc) {
  if (**string == '*' || **string == '/' || **string == '^') {
    int cur_prior = model.s21_get_priority(model.get_type(**string));
    model.overflow(cur_prior, head_num, head_calc);
    model.push(head_calc, 0, (type_f)model.get_type(*(*string)++));
  }
  if (**string == '+' || **string == '-') {
    if (model.is_unar(string, head_num, head_calc)) {
      model.push(head_num, 0, (type_f)1);
    }
    int cur_prior = model.s21_get_priority(model.get_type(**string));
    model.overflow(cur_prior, head_num, head_calc);
    model.push(head_calc, 0, (type_f)model.get_type(*(*string)++));
  }
}

void Controll::long_calc_parser(char **string, Stack **head_num, Stack **head_calc) {
  if (strlen(*string) >= 3) {
    if ((*string)[0] == 'm' && (*string)[1] == 'o' && (*string)[2] == 'd') {
      model.overflow(2, head_num, head_calc);
      model.push(head_calc, 0, (type_f)7);
      *string += 3;
    }
  }
  if (strlen(*string) >= 4 && (*string)[0] == 's') {
    if ((*string)[1] == 'q' && (*string)[2] == 'r' && (*string)[3] == 't') {
      model.overflow(4, head_num, head_calc);
      model.push(head_calc, 0, (type_f)9);
      *string += 4;
    }
  }
  if (strlen(*string) >= 3 && (*string)[0] == 'l') {
    if ((*string)[1] == 'n') {
      model.overflow(4, head_num, head_calc);
      model.push(head_calc, 0, (type_f)16);
      *string += 2;
    }
    if ((*string)[1] == 'o' && (*string)[2] == 'g') {
      model.overflow(4, head_num, head_calc);
      model.push(head_calc, 0, (type_f)17);
      *string += 3;
    }
  }
}

void Controll::trig_parser(char **string, Stack **head_num, Stack **head_calc) {
  if (strlen(*string) >= 3) {
    if ((*string)[0] == 's' && (*string)[1] == 'i' && (*string)[2] == 'n') {
      model.overflow(4, head_num, head_calc);
      model.push(head_calc, 0, (type_f)10);
      *string += 3;
    }
    if ((*string)[0] == 'c' && (*string)[1] == 'o' && (*string)[2] == 's') {
      model.overflow(4, head_num, head_calc);
      model.push(head_calc, 0, (type_f)11);
      *string += 3;
    }
    if ((*string)[0] == 't' && (*string)[1] == 'a' && (*string)[2] == 'n') {
      model.overflow(4, head_num, head_calc);
      model.push(head_calc, 0, (type_f)12);
      *string += 3;
    }
  }
}

void Controll::ltrig_parser(char **string, Stack **head_num, Stack **head_calc) {
  if (strlen(*string) >= 4 && (*string)[0] == 'a') {
    if ((*string)[1] == 's' && (*string)[2] == 'i' && (*string)[3] == 'n') {
      model.overflow(4, head_num, head_calc);
      model.push(head_calc, 0, (type_f)13);
      *string += 4;
    }
    if ((*string)[1] == 'c' && (*string)[2] == 'o' && (*string)[3] == 's') {
      model.overflow(4, head_num, head_calc);
      model.push(head_calc, 0, (type_f)14);
      *string += 4;
    }
    if ((*string)[1] == 't' && (*string)[2] == 'a' && (*string)[3] == 'n') {
      model.overflow(4, head_num, head_calc);
      model.push(head_calc, 0, (type_f)15);
      *string += 4;
    }
  }
}

void Controll::bracket_parser(char **string, Stack **head_num, Stack **head_calc) {
  if (**string == '(') {
        model.push(head_calc, 0, (type_f)18);
    (*string)++;
  }
  if (**string == ')') {
    Stack *tmp;
    while ((*head_calc)->type != 18) {
      model.push(head_num, 0, (*head_calc)->type);
      tmp = model.pop(head_calc);
      free(tmp);
    }
    tmp = model.pop(head_calc);
    free(tmp);
    (*string)++;
  }
}

void Controll::fin_parser(Stack **head_num, Stack **head_calc) {
  Stack *tmp;
  while (*head_num != NULL) {
    model.push(head_calc, (*head_num)->value, (*head_num)->type);
    tmp = model.pop(head_num);
    free(tmp);
  }
}

int Controll::s21_parser(char *string, Stack **head_num, Stack **head_calc, double x) {
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
