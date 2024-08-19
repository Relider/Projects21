
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int initial_flags(int *options, int *argc, char **argv, char *error, int n_file,
                  int *max_file, int n_option, int *max_option, char **option,
                  int *file, int *true_opt, int *is_e);
int search(char *list, char *pattern, int *options, int O_start);

int main(int argc, char **argv) {
  int options[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  char error[5] = {0, 0, 0, 0, 0}, *option = calloc(2, sizeof(char));
  int max_file = 1, file = 0;
  int max_option = 1, true_opt = 0;
  if (argc != 1) {
    FILE *fp = NULL;
    for (int n_file = 1; n_file <= max_file; n_file++) {
      int n_option = 1, kol_vo_str = 0, kol_vo_strinfile = 0, is_e = 0;
      initial_flags(options, &argc, argv, error, n_file, &max_file, n_option,
                    &max_option, &option, &file, &true_opt, &is_e);
      fp = fopen(argv[initial_flags(options, &argc, argv, error, n_file,
                                    &max_file, n_option, &max_option, &option,
                                    &file, &true_opt, &is_e)],
                 "r");
      if (file == 0) {
        fp = 0;
      }
      if (fp != 0) {
        if (error[0] == 0) {
          int flag = 0;

          while (flag != 1) {
            int n = 100;
            char *list = (char *)calloc((n + 2), sizeof(char));
            int i = 0, c = 1;

            while (c != '\n' && flag != 1) {
              if (n <= i) {
                n *= 2;
                char var[n / 2];
                for (int k = 0; k < n / 2; k++) {
                  var[k] = list[k];
                }
                free(list);
                list = calloc((n + 2), sizeof(char));
                for (int k = 0; k < n / 2; k++) {
                  list[k] = var[k];
                }
              }
              c = fgetc(fp);
              if (c != EOF && c != '\0') {
                list[i++] = c;
              } else {
                flag = 1;
              }
            }
            kol_vo_strinfile += 1;

            int num_opt = 0, O_start = 0, flag_9 = 0;
            for (int n_option = 1; n_option <= max_option; n_option++) {
              initial_flags(options, &argc, argv, error, n_file, &max_file,
                            n_option, &max_option, &option, &file, &true_opt,
                            &is_e);
              if ((options[2] == 1 && search(list, option, options, 0) == -1) &&
                  i > 0) {
                num_opt += 1;
              }
              if (((options[2] == 0 &&
                    search(list, option, options, 0) != -1) ||
                   num_opt == max_option || true_opt == 1) &&
                  i > 0) {
                if (options[3] == 0 && options[4] == 0) {
                  if (max_file != 1 && options[6] == 0) {
                    printf("%s:", argv[file]);
                  }
                  if (options[5] == 1) {
                    if (!(flag_9 == 1 && options[9] == 1)) {
                      printf("%d:", kol_vo_strinfile);
                    }
                    flag_9 = 1;
                  }
                  if (options[9] != 1 || true_opt == 1 || options[2] == 1) {
                    for (int k = 0; k < i; k++) {
                      printf("%c", list[k]);
                    }
                  } else {
                    int N = search(list, option, options, O_start);
                    while (N != -1) {
                      for (int k = N; k < N + (int)strlen(option); k++) {
                        printf("%c", list[k]);
                      }
                      printf("\n");
                      O_start = N + (int)strlen(option);
                      N = search(list, option, options, O_start);
                    }
                  }
                  if (list[i - 1] != '\n' &&
                      (options[9] != 1 || options[2] == 1)) {
                    printf("\n");
                  }
                } else {
                  kol_vo_str += 1;
                  if (options[3] == 1) {
                    n_option = max_option + 1;
                  }
                }
                if (options[9] != 1) {
                  n_option = max_option + 1;
                }
                true_opt = 0;
              }
            }
            free(list);
          }
          if (options[3] == 1) {
            if (max_file != 1 && options[6] == 0) {
              printf("%s:", argv[file]);
            }
            if (options[4] == 1) {
              if (kol_vo_str > 0) {
                printf("%d\n", 1);
              } else {
                printf("%d\n", 0);
              }
            } else {
              printf("%d\n", kol_vo_str);
            }
          }
          if (options[4] == 1 && kol_vo_str != 0) {
            printf("%s\n", argv[file]);
          }
        } else {
          fprintf(stderr, "s21_grep: Invalid argument\n");
          n_file = max_file + 1;
        }
      } else {
        if (options[7] == 0) {
          fprintf(stderr, "s21_grep: %s: No such file or directory\n",
                  argv[file]);
        }
      }
      fclose(fp);
    }
  } else {
    fprintf(stderr, "error");
  }
  free(option);
  return 0;
}

int initial_flags(int *options, int *argc, char **argv, char *error, int n_file,
                  int *max_file, int n_option, int *max_option, char **option,
                  int *file, int *true_opt, int *is_e) {
  int file_reg = 0, option_reg = 0, flag_option = 0, flag_file_option = 0;
  for (int i = 1; i < *argc; i++) {
    if (argv[i][0] == '-' && flag_option != 1 && flag_file_option != 1) {
      for (int j = 1; j < (int)strlen(argv[i]); j++) {
        if (flag_option == 1) {
          option_reg += 1;
          flag_option = 0;
          if (option_reg == n_option) {
            free(*option);
            *option = NULL;
            if (!(*option = (char *)calloc(((int)strlen(argv[i]) + 2),
                                           sizeof(char)))) {
              printf("error");
              return 1;
            }
            int num = 0;
            for (; j < (int)strlen(argv[i]); j++) {
              (*option)[num++] = argv[i][j];
            }
          }
          break;
        }
        if (flag_file_option == 1) {
          FILE *f2p;
          int n = 10;
          char boxs[(int)strlen(argv[i])];
          int num = 0;
          for (; j < (int)strlen(argv[i]); j++) {
            boxs[num++] = argv[i][j];
          }
          f2p = fopen(boxs, "r");
          if (f2p != 0) {
            while (flag_file_option != 0) {
              int sch = 0;
              char *box = calloc((n + 2), sizeof(char));
              char c = 0;
              while (c != '\n' && flag_file_option != 0) {
                if (n <= sch) {
                  n *= 2;
                  box = realloc(box, (n + 2) * sizeof(char));
                }
                if (fscanf(f2p, "%c", &c) != EOF) {
                  if (c != '\n') {
                    box[sch++] = c;
                  }
                } else {
                  flag_file_option = 0;
                }
              }

              option_reg += 1;
              if (option_reg == n_option) {
                free(*option);
                *option = NULL;
                *option = (char *)calloc((strlen(box) + 2), sizeof(char));
                int j = 0;
                for (; j < (int)strlen(box); j++) {
                  (*option)[j] = box[j];
                }
                if (strlen(box) == 0 && flag_file_option != 0) {
                  *true_opt = 1;
                }
              }
              free(box);
            }
          } else {
            error[0] = 1;
            error[1] = i;
          }
          fclose(f2p);
          break;
        }

        if (argv[i][j] == 'e') {
          *is_e = 1;
          options[0] += 1;
          flag_option = 1;
          continue;
        }
        if (argv[i][j] == 'i') {
          options[1] = 1;
          continue;
        }
        if (argv[i][j] == 'v') {
          options[2] = 1;
          continue;
        }
        if (argv[i][j] == 'c') {
          options[3] = 1;
          continue;
        }
        if (argv[i][j] == 'l') {
          options[4] = 1;
          continue;
        }
        if (argv[i][j] == 'n') {
          options[5] = 1;
          continue;
        }
        if (argv[i][j] == 'h') {
          options[6] = 1;
          continue;
        }
        if (argv[i][j] == 's') {
          options[7] = 1;
          continue;
        }
        if (argv[i][j] == 'f') {
          options[8] = 1;
          flag_file_option = 1;
          continue;
        }
        if (argv[i][j] == 'o') {
          options[9] = 1;
          continue;
        }
        error[0] = argv[i][0];
        error[1] = argv[i][j];
      }
    } else {
      if (flag_file_option == 1) {
        FILE *f2p;
        int n = 10;
        f2p = fopen(argv[i], "r");
        if (f2p != 0) {
          while (flag_file_option != 0) {
            int sch = 0;
            char *box = (char *)calloc((n + 2), sizeof(char));
            char c = 0;
            while (c != '\n' && flag_file_option != 0) {
              if (n <= sch) {
                n *= 2;
                box = realloc(box, (n + 2) * sizeof(char));
              }
              if (fscanf(f2p, "%c", &c) != EOF) {
                if (c != '\n') {
                  box[sch++] = c;
                }
              } else {
                flag_file_option = 0;
              }
            }

            option_reg += 1;
            if (option_reg == n_option) {
              free(*option);
              *option = NULL;
              *option = (char *)calloc((strlen(box) + 2), sizeof(char));
              int j = 0;
              for (; j < (int)strlen(box); j++) {
                (*option)[j] = box[j];
              }
              if (strlen(box) == 0 && flag_file_option != 0) {
                *true_opt = 1;
              }
            }
            for (int k = 0; k < (int)strlen(box); k++) {
              box[k] = 0;
            }
            free(box);
          }
        } else {
          error[0] = 1;
          error[1] = i;
        }
        fclose(f2p);
      } else {
        if (flag_option == 1 || (option_reg == 0 && *is_e == 0)) {
          option_reg += 1;
          flag_option = 0;
          if (option_reg == n_option || *is_e == 0) {
            free(*option);
            *option = NULL;
            *option = (char *)calloc((strlen(argv[i]) + 2), sizeof(char));
            int j = 0;
            for (; j < (int)strlen(argv[i]); j++) {
              (*option)[j] = argv[i][j];
            }
          }
        } else {
          file_reg += 1;
          if (file_reg == n_file) {
            *file = i;
          }
        }
      }
    }
  }
  *max_file = file_reg;
  *max_option = option_reg;
  if (file_reg == 0) {
    *file = 0;
  }
  return *file;
}

int search(char *list, char *pattern, int *options, int O_start) {
  regex_t preg;
  const size_t nmatch = 0;
  regmatch_t p_match[1];
  int er, res = O_start - 1, N = strlen(list), Np = (int)strlen(pattern);
  if (options[1] == 1) {
    er = regcomp(&preg, pattern, REG_EXTENDED | REG_ICASE);
  } else {
    er = regcomp(&preg, pattern, REG_EXTENDED);
  }
  if (!er && (N - O_start >= Np)) {
    char list2[N + 2];
    for (int j = 0; j < N + 2; j++) {
      list2[j] = 0;
    }
    do {
      res += 1;
      for (int i = res, j = 0; i < res + Np; i++, j++) {
        list2[j] = list[i];
      }
      er = regexec(&preg, list2, nmatch, p_match, 0);
    } while (er && (res < N - Np));
  } else {
    res = -1;
  }
  if (er != 0) {
    res = -1;
  }
  regfree(&preg);
  return res;
}

// int search(char *list, char *pattern, int *options, int O_start) {
// regex_t preg;
// const size_t nmatch = 1;
// regmatch_t p_match[1];
// int er, res = O_start, N = (int)strlen(list), Np = (int)strlen(pattern);
// if (N >= Np){
// if (options[1] == 1) {
//   er = regcomp(&preg, pattern, REG_EXTENDED | REG_ICASE);
// } else {
//   er = regcomp(&preg, pattern, REG_EXTENDED);
// }
// if (!er) {
//   char list2[N];
//   for (int i = res, j = 0; i < N; i++, j++) {
//     list2[j] = list[i];
//   }
//   er = regexec(&preg, list2, nmatch, p_match, 0);
//   if(er == 0){
//     res = p_match[0].rm_so;
//   } else {
//     res=-1;
//   }
// }
// regfree(&preg);
// }
// printf("%d", res);
// return res;
// }
