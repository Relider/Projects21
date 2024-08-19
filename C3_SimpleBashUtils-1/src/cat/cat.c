#include <stdio.h>
#include <string.h>

void numeric(int *options, char last, char list, int *string);
int initial(int *options, int *argc, char **argv, char *error, int pov);
int kolvo(int argc, char **argv);
void find_option_standart(int i, int file, int *options, int *argc, char *error,
                          char **argv);
void find_option_GNU(int i, int *options, int *argc, char **argv);

int main(int argc, char **argv) {
  int options[6] = {0, 0, 0, 0, 0, 0};
  char error[3] = {0, 0, 0};

  if (argc != 1) {
    FILE *fp;
    for (int pov = 1; pov <= kolvo(argc, argv); pov++) {
      int string = 1, entr = 0;
      fp = fopen(argv[initial(options, &argc, argv, error, pov)], "r");

      if (fp != 0) {
        char list = 0, last = -5, l2ast = 0;
        while (fscanf(fp, "%c", &list) != EOF) {
          if (!(list == last && last == l2ast && options[4] == 1 &&
                list == '\n') &&
              !(options[5] == 1 && list == 9) &&
              !((options[0] == 1) &&
                ((list >= 0 && list < 9) || (list > 10 && list <= 31) ||
                 list == 127))) {
            numeric(options, last, list, &string);
            printf("%c", list);
          }

          if ((options[0] == 1) && ((list >= 0 && list < 9) ||
                                    (list > 10 && list <= 31) || list == 127)) {
            numeric(options, last, list, &string);
            printf("^%c", (list + 64) % 128);
          }

          if (list == last && last == l2ast && options[4] == 1 &&
              list == '\n') {
            if (entr == 0) {
              entr = 1;
            }
          }
          if (list != last) {
            entr = 0;
          }

          if (list == 9 && options[5] == 1) {
            numeric(options, last, list, &string);
            printf("^I");
          }

          l2ast = last;
          last = list;
        }
        if (error[0] != 0) {
          fprintf(stderr, "s21_cat: %s: No such file or directory", error);
        }
        fclose(fp);
      } else {
        fprintf(stderr, "s21_cat: %s: No such file or directory",
                argv[initial(options, &argc, argv, error, pov)]);
      }
    }
  } else {
    fprintf(stderr, "error");
  }
}

int initial(int *options, int *argc, char **argv, char *error, int pov) {
  int file = 0, reg = 0;
  for (int i = 2; i < *argc + 1; i++) {
    if (argv[i - 1][0] == '-') {
      if (argv[i - 1][1] == '-') {
        find_option_GNU(i, options, argc, argv);
      } else {
        find_option_standart(i, file, options, argc, error, argv);
      }
    } else {
      reg += 1;
      if (reg == pov) {
        file = i - 1;
      }
    }
  }
  return file;
}

void numeric(int *options, char last, char list, int *string) {
  if (((last == 10 || *string == 1) && last != list && list != 10 &&
       options[1] == 1)) {
    printf("%6d%c", *string, 9);
    *string += 1;
  }
  if ((last == 10 || *string == 1) && options[1] != 1 && options[3] == 1) {
    printf("%6d%c", *string, 9);
    *string += 1;
  }
  if (list == 10 && options[2] == 1) {
    printf("$");
  }
}

int kolvo(int argc, char **argv) {
  int res = 0;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-') {
      res += 1;
    }
  }
  return res;
}

void find_option_GNU(int i, int *options, int *argc, char **argv) {
  int flag = 0;
  if (strcmp(argv[i - 1], "--number-nonblank") == 0) {
    options[1] = 1;
    flag = 1;
  }
  if (strcmp(argv[i - 1], "--number") == 0) {
    options[3] = 1;
    flag = 1;
  }
  if (strcmp(argv[i - 1], "--squeeze-blank") == 0) {
    options[4] = 1;
    flag = 1;
  }
  if (flag != 1) {
    *argc = 1;
  }
}

void find_option_standart(int i, int file, int *options, int *argc, char *error,
                          char **argv) {
  for (int j = 1; j < (int)strlen(argv[i - 1]); j++) {
    if (argv[i - 1][j] == 'b') {
      if (file == 0) {
        options[1] = 1;
        continue;
      } else {
        error[0] = '-';
        error[1] = 'b';
      }
    }
    if (argv[i - 1][j] == 'E') {
      if (file == 0) {
        options[2] = 1;
        continue;
      } else {
        error[0] = '-';
        error[1] = 'b';
      }
    }
    if (argv[i - 1][j] == 'e') {
      if (file == 0) {
        options[2] = 1;
        options[0] = 1;
        continue;
      } else {
        error[0] = '-';
        error[1] = 'b';
      }
    }
    if (argv[i - 1][j] == 'n') {
      if (file == 0) {
        options[3] = 1;
        continue;
      } else {
        error[0] = '-';
        error[1] = 'b';
      }
    }
    if (argv[i - 1][j] == 's') {
      options[4] = 1;
      continue;
    }
    if (argv[i - 1][j] == 'T') {
      options[5] = 1;
      continue;
    }
    if (argv[i - 1][j] == 't') {
      options[5] = 1;
      options[0] = 1;
      continue;
    }
    if (argv[i - 1][j] == 'v') {
      options[0] = 1;
      continue;
    }
    *argc = 1;
  }
}
