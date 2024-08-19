#include <gtest/gtest.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../SmartCalc/s21_Controll.h"

#define ERROR 0.000001

TEST(s21_SmartCalc, test_1) {
  Controll controll;
  const char *string = "2 + 2 * 5 - 1";
  double result;
  int error = controll.s21_SmartCalc((char*)string, 0, &result);
  EXPECT_NEAR(error, 0, ERROR);
  EXPECT_NEAR(result, 11.0, ERROR);
}

TEST(s21_SmartCalc, test_2) {
  Controll controll;
  const char *string = "(2 + e ^ 1) / (5 - 1)";
  double result;
  int error = controll.s21_SmartCalc((char*)string, 0, &result);
  EXPECT_NEAR(error, 0, ERROR);
  EXPECT_NEAR(result, 1.1795705, ERROR);
}

TEST(s21_SmartCalc, test_3) {
  Controll controll;
  const char *string = "(-(2 + 2) * 5) - 1 + sin(pi)";
  double result;
  int error = controll.s21_SmartCalc((char*)string, 0, &result);
  EXPECT_NEAR(error, 0, ERROR);
  EXPECT_NEAR(result, -21.0, ERROR);
}

TEST(s21_SmartCalc, test_4) {
  Controll controll;
  const char *string = "-2 + (+2) * 5 - sqrt(9) mod 10";
  double result;
  int error = controll.s21_SmartCalc((char*)string, 0, &result);
  EXPECT_NEAR(error, 0, ERROR);
  EXPECT_NEAR(result, 5.0, ERROR);
}

TEST(s21_SmartCalc, test_5) {
  Controll controll;
  const char *string = "sin(1+3) - cos(1*2) + tan(0)";
  double result;
  int error = controll.s21_SmartCalc((char*)string, 0, &result);
  EXPECT_NEAR(error, 0, ERROR);
  EXPECT_NEAR(result, -0.340656, ERROR);
}

TEST(s21_SmartCalc, test_6) {
  Controll controll;
  const char *string = "atan(5)+acos(0)+asin(0.25)";
  double result;
  int error = controll.s21_SmartCalc((char*)string, 0, &result);
  EXPECT_NEAR(error, 0, ERROR);
  EXPECT_NEAR(result, 3.1492942, ERROR);
}

TEST(s21_SmartCalc, test_7) {
  Controll controll;
  const char *string = "ln(12) - log(120)";
  double result;
  int error = controll.s21_SmartCalc((char*)string, 0, &result);
  EXPECT_NEAR(error, 0, ERROR);
  EXPECT_NEAR(result, 0.4057254, ERROR);
}

TEST(s21_SmartCalc, test_8) {
  Controll controll;
  const char *string = "0.0000001+0.0000001";
  double result;
  int error = controll.s21_SmartCalc((char*)string, 0, &result);
  EXPECT_NEAR(error, 0, ERROR);
  EXPECT_NEAR(result, 0.0000002, ERROR);
}

TEST(s21_SmartCalc, test_9) {
  Controll controll;
  const char *string = "0.04+2+";
  double result;
  int error = controll.s21_SmartCalc((char*)string, 0, &result);
  EXPECT_NE(error, 0);
}

TEST(s21_SmartCalc, test_10) {
  Controll controll;
  const char *string = "0.04+*2";
  double result;
  int error = controll.s21_SmartCalc((char*)string, 0, &result);
  EXPECT_NE(error, 0);
}

TEST(s21_SmartCalc, test_11) {
  Controll controll;
  const char *string = "0.04 + 2 x";
  double result;
  int error = controll.s21_SmartCalc((char*)string, 0, &result);
  EXPECT_NE(error, 0);
}

TEST(s21_SmartCalc, test_12) {
  Controll controll;
  const char *string = "3 qdf 4 + 2";
  double result;
  int error = controll.s21_SmartCalc((char*)string, 0, &result);
  EXPECT_NE(error, 0);
}

TEST(s21_SmartCalc, test_13) {
  Controll controll;
  const char *string = "3,2 + 1";
  double result;
  int error = controll.s21_SmartCalc((char*)string, 0, &result);
  EXPECT_NE(error, 0);
}

int main(int argc, char*argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
