#include "s21_Controll.h"

void Controll::common_calc(Stack **head_num, Stack **head_calc) {
  Stack *tmp;
  if (*head_calc != NULL && (*head_calc)->type == 3) {
    if (*head_num != NULL && (*head_num)->next != NULL) {
      tmp = model.pop(head_calc);
      free(tmp);
      tmp = model.pop(head_num);
      (*head_num)->value += tmp->value;
      free(tmp);
    }
  }
  if (*head_calc != NULL && (*head_calc)->type == 4) {
    if (*head_num != NULL && (*head_num)->next != NULL) {
      tmp = model.pop(head_calc);
      free(tmp);
      tmp = model.pop(head_num);
      (*head_num)->value -= tmp->value;
      free(tmp);
    }
  }
  if (*head_calc != NULL && (*head_calc)->type == 5) {
    if (*head_num != NULL && (*head_num)->next != NULL) {
      tmp = model.pop(head_calc);
      free(tmp);
      tmp = model.pop(head_num);
      (*head_num)->value *= tmp->value;
      free(tmp);
    }
  }
  if (*head_calc != NULL && (*head_calc)->type == 6) {
    if (*head_num != NULL && (*head_num)->next != NULL) {
      tmp = model.pop(head_calc);
      free(tmp);
      tmp = model.pop(head_num);
      (*head_num)->value /= tmp->value;
      free(tmp);
    }
  }
}

void Controll::hard_calc(Stack **head_num, Stack **head_calc) {
  Stack *tmp;
  if (*head_calc != NULL && (*head_calc)->type == 7) {
    if (*head_num != NULL && (*head_num)->next != NULL) {
      tmp = model.pop(head_calc);
      free(tmp);
      tmp = model.pop(head_num);
      (*head_num)->value = fmod((*head_num)->value, tmp->value);
      free(tmp);
    }
  }
  if (*head_calc != NULL && (*head_calc)->type == 8) {
    if (*head_num != NULL && (*head_num)->next != NULL) {
      tmp = model.pop(head_calc);
      free(tmp);
      tmp = model.pop(head_num);
      (*head_num)->value = powf((*head_num)->value, tmp->value);
      free(tmp);
    }
  }
  if (*head_calc != NULL && (*head_calc)->type == 9) {
    if (*head_num != NULL) {
      tmp = model.pop(head_calc);
      free(tmp);
      (*head_num)->value = sqrt((*head_num)->value);
    }
  }
  if (*head_calc != NULL && (*head_calc)->type == 16) {
    if (*head_num != NULL) {
      tmp = model.pop(head_calc);
      free(tmp);
      (*head_num)->value = log((*head_num)->value);
    }
  }
  if (*head_calc != NULL && (*head_calc)->type == 17) {
    if (*head_num != NULL) {
      tmp = model.pop(head_calc);
      free(tmp);
      (*head_num)->value = log10((*head_num)->value);
    }
  }
}

void Controll::trig_calc(Stack **head_num, Stack **head_calc) {
  Stack *tmp;
  if (*head_calc != NULL && (*head_calc)->type == 10) {
    if (*head_num != NULL) {
      tmp = model.pop(head_calc);
      free(tmp);
      (*head_num)->value = sin((*head_num)->value);
    }
  }
  if (*head_calc != NULL && (*head_calc)->type == 11) {
    if (*head_num != NULL) {
      tmp = model.pop(head_calc);
      free(tmp);
      (*head_num)->value = cos((*head_num)->value);
    }
  }
  if (*head_calc != NULL && (*head_calc)->type == 12) {
    if (*head_num != NULL) {
      tmp = model.pop(head_calc);
      free(tmp);
      (*head_num)->value = tan((*head_num)->value);
    }
  }
  if (*head_calc != NULL && (*head_calc)->type == 13) {
    if (*head_num != NULL) {
      tmp = model.pop(head_calc);
      free(tmp);
      (*head_num)->value = asin((*head_num)->value);
    }
  }
  if (*head_calc != NULL) {
    if (*head_num != NULL && (*head_calc)->type == 14) {
      tmp = model.pop(head_calc);
      free(tmp);
      (*head_num)->value = acos((*head_num)->value);
    }
  }
  if (*head_calc != NULL && (*head_calc)->type == 15) {
    if (*head_num != NULL) {
      tmp = model.pop(head_calc);
      free(tmp);
      (*head_num)->value = atan((*head_num)->value);
    }
  }
}

int Controll::s21_calculate(Stack **head_num, Stack **head_calc, double *result) {
  Stack *tmp, *safe_poz;
  int err_code = 0;
  while (*head_calc != NULL && !err_code) {
    safe_poz = *head_calc;
    if ((*head_calc)->type == 1) {
        model.push(head_num, (*head_calc)->value, (type_f)1);
      tmp = model.pop(head_calc);
      free(tmp);
    } else {
      common_calc(head_num, head_calc);
      hard_calc(head_num, head_calc);
      trig_calc(head_num, head_calc);
    }
    if (safe_poz == *head_calc) {
      err_code = 1;
    }
  }
  while (*head_calc != NULL) {
    *result = model.peek(*head_calc);
    tmp = model.pop(head_calc);
    free(tmp);
    err_code++;
  }
  if (*head_num != NULL) err_code -= 1;
  while (*head_num != NULL) {
    *result = model.peek(*head_num);
    tmp = model.pop(head_num);
    free(tmp);
    err_code++;
  }
  return err_code;
}
