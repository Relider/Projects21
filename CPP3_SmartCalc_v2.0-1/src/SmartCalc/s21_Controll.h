#ifndef S21_CONTROLL_H
#define S21_CONTROLL_H

#include "s21_Model.h"

class Controll{
private:
    Model model;
public:
    Controll() {};
    ~Controll() {};

    int s21_SmartCalc(char *string, double x, double *result);
    int s21_calculate(Stack **head_num, Stack **head_calc, double *result);
    int s21_parser(char *string, Stack **head_out, Stack **head_calc, double x);
    int s21_error_func(char *string);
    int expression_error(char *string);
    void common_calc(Stack **head_num, Stack **head_calc);
    void hard_calc(Stack **head_num, Stack **head_calc);
    void trig_calc(Stack **head_num, Stack **head_calc);
    void num_parser(char **string, Stack **head_num, double x);
    void calc_parser(char **string, Stack **head_num, Stack **head_calc);
    void long_calc_parser(char **string, Stack **head_num, Stack **head_calc);
    void trig_parser(char **string, Stack **head_num, Stack **head_calc);
    void ltrig_parser(char **string, Stack **head_num, Stack **head_calc);
    void bracket_parser(char **string, Stack **head_num, Stack **head_calc);
    void fin_parser(Stack **head_num, Stack **head_calc);
};

#endif  // S21_CONTROLL_H
