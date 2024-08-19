#include "s21_3dviewer.h"

void push_in_all_coord(viewer *head, int *count_all_coord) {
  int amount_coord = head->v->amount_coord - 1;
  head->v->all_coord[*count_all_coord] = head->v->coord[amount_coord].x;
  head->v->all_coord[*count_all_coord + 1] = head->v->coord[amount_coord].y;
  head->v->all_coord[*count_all_coord + 2] = head->v->coord[amount_coord].z;
  *count_all_coord += 3;
}

int v_parser(viewer *head, char *input, int *count_all_coord) {
  double x, y, z;
  int error_code = (sscanf(input, "v %lf %lf %lf\n", &x, &y, &z)) ? 0 : 1;
  if (!error_code) {
    push_coord(head, x, y, z);
    push_in_all_coord(head, count_all_coord);
  }
  return error_code;
}

void push_in_all_p(viewer *head) {
  int j = 0;
  int i = 0;
  while (i < *head->amount_polygon) {
    int first_number = head->p[i].p[0];
    int number = 1;
    head->p->all_p[j++] = first_number - 1;
    for (int h = 1; h < head->p->amount_p; h++) {
      number = head->p[i].p[h];
      head->p->all_p[j++] = number - 1;
      head->p->all_p[j++] = number - 1;
    }
    head->p->all_p[j] = first_number - 1;
    if (j + 1 < (*head->amount_polygon) * head->p->amount_p * 2) {
      j++;
    }
    i++;
  }
}

int f_parser(viewer *head, char *input) {
  int error_code = (input[0] == 'f' && input[1] == ' ') ? 0 : 1;
  if (!error_code) {
    int p, data;
    input += 2;
    while (sscanf(input, "%d%n", &p, &data) > 0) {
      push_polygon(head, p);
      input += data;
    }
    push_polygon(head, 0);
  }
  return error_code;
}

void out_of_char(char **input, int i) {
  if (is_border(i)) {
    *input = realloc(*input, (i * 10 + 1) * sizeof(char));
  }
}

int readline(FILE *file, char **input) {
  int result = 0, i = 0;
  while (((*input)[i] = fgetc(file)) != '\n' && (*input)[i++] != EOF) {
    out_of_char(input, i);
    result = 1;
  }
  (*input)[i] = '\0';
  return result;
}

int s21_get_input(viewer *head, char *path) {
  int error_code = 1;
  FILE *file;
  file = fopen(path, "r");
  if (file) {
    error_code = 0;
    int count_all_coord = 0;  // 0
    head->v->all_coord[0] = 0;
    char *input = calloc(100001, sizeof(char));
    while (!error_code && readline(file, &input)) {
      error_code += v_parser(head, input, &count_all_coord);
      error_code += f_parser(head, input);
      error_code += !(input[0] == '#' || input[0] == 10 || input[0] == 13);
      error_code = (error_code < 3) ? 0 : 1;
      free(input);
      input = calloc(100001, sizeof(char));
    }
    push_in_all_p(head);
    head->p->amount_edges = *head->amount_polygon * 2;
    free(input);
    fclose(file);
  }
  return error_code;
}
