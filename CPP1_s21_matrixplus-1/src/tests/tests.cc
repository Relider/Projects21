#include <gtest/gtest.h>

#include <cmath>
#include <iostream>
#include <vector>

#include "../s21_matrix_oop.h"

TEST(matrixTest, EqMatrixTest1) {
  S21Matrix matrix1(2, 3), matrix2(2, 3);
  matrix1(0, 0) = 1;
  matrix1(1, 0) = 1;
  matrix1(0, 1) = 1;
  matrix1(1, 1) = 3;
  matrix1(0, 2) = 1;
  matrix1(1, 2) = 2.3;

  matrix2(0, 0) = 1;
  matrix2(1, 0) = 1;
  matrix2(0, 1) = 1;
  matrix2(1, 1) = 3;
  matrix2(0, 2) = 1;
  matrix2(1, 2) = 2.3;

  EXPECT_TRUE(matrix1.EqMatrix(matrix2));
}

TEST(matrixTest, EqMatrixTest2) {
  S21Matrix matrix1(3, 3), matrix2(3, 3);
  matrix1(0, 0) = 9;
  matrix1(0, 1) = -2;
  matrix1(0, 2) = -3;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 14;
  matrix1(1, 1) = -1;
  matrix1(2, 0) = -7;
  matrix1(2, 1) = -18;
  matrix1(2, 1) = 17;

  matrix2(0, 0) = 9;
  matrix2(0, 1) = -2;
  matrix2(0, 2) = -3;
  matrix2(1, 0) = 3;
  matrix2(1, 1) = 14;
  matrix2(1, 1) = -1;
  matrix2(2, 0) = -7;
  matrix2(2, 1) = -18;
  matrix2(2, 1) = 17;

  EXPECT_TRUE(matrix1 == matrix2);
}

TEST(matrixTest, SumMatrixTest) {
  S21Matrix matrix1(2, 3), matrix2(2, 3), matrix3(2, 3), result(2, 3);
  matrix1(0, 0) = 1;
  matrix1(1, 0) = 1;
  matrix1(0, 1) = 1;
  matrix1(1, 1) = 3;
  matrix1(0, 2) = 1;
  matrix1(1, 2) = -2.3;

  matrix2(0, 0) = 1;
  matrix2(1, 0) = 0.2;
  matrix2(0, 1) = -3;
  matrix2(1, 1) = 1;
  matrix2(0, 2) = 4;
  matrix2(1, 2) = 2.3;

  result(0, 0) = 2;
  result(1, 0) = 1.2;
  result(0, 1) = -2;
  result(1, 1) = 4;
  result(0, 2) = 5;
  result(1, 2) = 0;

  matrix3 = matrix1;
  matrix3 += matrix2;
  EXPECT_TRUE(result.EqMatrix(matrix3));

  matrix3 = matrix1 + matrix2;
  EXPECT_TRUE(result.EqMatrix(matrix3));

  matrix1.SumMatrix(matrix2);
  EXPECT_TRUE(result.EqMatrix(matrix1));
}

TEST(matrixTest, SubMatrixTest) {
  S21Matrix matrix1(2, 3), matrix2(2, 3), matrix3(2, 3), result(2, 3);
  matrix1(0, 0) = 1;
  matrix1(1, 0) = 1;
  matrix1(0, 1) = 1;
  matrix1(1, 1) = 3;
  matrix1(0, 2) = 1;
  matrix1(1, 2) = -2.3;

  matrix2(0, 0) = 1;
  matrix2(1, 0) = 0.2;
  matrix2(0, 1) = -3;
  matrix2(1, 1) = 1;
  matrix2(0, 2) = 4;
  matrix2(1, 2) = 2.3;

  result(0, 0) = 0;
  result(1, 0) = 0.8;
  result(0, 1) = 4;
  result(1, 1) = 2;
  result(0, 2) = -3;
  result(1, 2) = -4.6;

  matrix3 = matrix1;
  matrix3 -= matrix2;
  EXPECT_TRUE(result.EqMatrix(matrix3));

  matrix3 = matrix1 - matrix2;
  EXPECT_TRUE(result.EqMatrix(matrix3));

  matrix1.SubMatrix(matrix2);
  EXPECT_TRUE(result.EqMatrix(matrix1));
}

TEST(matrixTest, mulNumberTest) {
  double number = 2.3;
  S21Matrix matrix(2, 3), matrix2(2, 3);

  matrix(0, 0) = 1;
  matrix(0, 1) = 1;
  matrix(0, 2) = 1;
  matrix(1, 0) = 1;
  matrix(1, 1) = 1;
  matrix(1, 2) = 1;

  matrix2 = matrix;
  matrix2 *= number;
  for (int i = 0; i < matrix.getRows(); i++) {
    for (int j = 0; j < matrix.getCols(); j++) {
      ASSERT_EQ(matrix2.getMatrixElement(i, j), number);
    }
  }

  matrix2 = matrix * number;
  for (int i = 0; i < matrix.getRows(); i++) {
    for (int j = 0; j < matrix.getCols(); j++) {
      ASSERT_EQ(matrix2.getMatrixElement(i, j), number);
    }
  }

  matrix.MulNumber(number);

  for (int i = 0; i < matrix.getRows(); i++) {
    for (int j = 0; j < matrix.getCols(); j++) {
      ASSERT_EQ(matrix.getMatrixElement(i, j), number);
    }
  }
}

TEST(matrixTest, operatorMulEqTest) {
  int rows = 2, cols = 3;
  S21Matrix matrix1(rows, cols), matrix2(cols, rows),
      matrix3(matrix1.getRows(), matrix2.getCols());
  S21Matrix result(matrix1.getRows(), matrix2.getCols());

  matrix1(0, 0) = 1.5;
  matrix1(0, 1) = -2.5;
  matrix1(0, 2) = 0.3;
  matrix1(1, 0) = 47;
  matrix1(1, 1) = -0.001;
  matrix1(1, 2) = 6;

  matrix2(0, 0) = -1;
  matrix2(0, 1) = 8.5;
  matrix2(1, 0) = 3.321321;
  matrix2(1, 1) = 4.1;
  matrix2(2, 0) = 5;
  matrix2(2, 1) = 6;

  result(0, 0) = -8.303303;
  result(0, 1) = 4.3;
  result(1, 0) = -17.003321;
  result(1, 1) = 435.4959;

  matrix3 = matrix1;
  matrix3 *= matrix2;
  for (int i = 0; i < matrix3.getRows(); i++) {
    for (int j = 0; j < matrix3.getCols(); j++) {
      EXPECT_NEAR(result.getMatrixElement(i, j), matrix3.getMatrixElement(i, j),
                  0.000001);
    }
  }

  matrix3 = matrix1 * matrix2;
  for (int i = 0; i < matrix3.getRows(); i++) {
    for (int j = 0; j < matrix3.getCols(); j++) {
      EXPECT_NEAR(result.getMatrixElement(i, j), matrix3.getMatrixElement(i, j),
                  0.000001);
    }
  }

  matrix1.MulMatrix(matrix2);
  for (int i = 0; i < result.getRows(); i++) {
    for (int j = 0; j < result.getCols(); j++) {
      EXPECT_NEAR(result.getMatrixElement(i, j), matrix1.getMatrixElement(i, j),
                  0.000001);
    }
  }
}

TEST(matrixTest, TransposeTest) {
  S21Matrix matrix1(2, 3), result(3, 2), matrix2(3, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 1;
  matrix1(0, 2) = 1;
  matrix1(1, 0) = 1;
  matrix1(1, 1) = 3;
  matrix1(1, 2) = -2.3;

  result(0, 0) = 1;
  result(0, 1) = 1;
  result(1, 0) = 1;
  result(1, 1) = 3;
  result(2, 0) = 1;
  result(2, 1) = -2.3;

  matrix2 = matrix1.Transpose();

  EXPECT_TRUE(result.EqMatrix(matrix2));
}

TEST(matrixTest, CalcComplementsTest) {
  S21Matrix matrix1(3, 3), result(3, 3), matrix2(3, 3);
  matrix1(0, 0) = 5;
  matrix1(0, 1) = -1;
  matrix1(0, 2) = 1;
  matrix1(1, 0) = 2;
  matrix1(1, 1) = 3;
  matrix1(1, 2) = 4;
  matrix1(2, 0) = 1;
  matrix1(2, 1) = 0;
  matrix1(2, 2) = 3;

  result(0, 0) = 9;
  result(0, 1) = -2;
  result(0, 2) = -3;
  result(1, 0) = 3;
  result(1, 1) = 14;
  result(1, 2) = -1;
  result(2, 0) = -7;
  result(2, 1) = -18;
  result(2, 2) = 17;

  matrix2 = matrix1.CalcComplements();

  EXPECT_TRUE(result.EqMatrix(matrix2));
}

TEST(matrixTest, DeterminantTest) {
  S21Matrix matrix1(3, 3);
  double result;
  matrix1(0, 0) = 5;
  matrix1(0, 1) = -1;
  matrix1(0, 2) = 1;
  matrix1(1, 0) = 2;
  matrix1(1, 1) = 3;
  matrix1(1, 2) = 4;
  matrix1(2, 0) = 1;
  matrix1(2, 1) = 0;
  matrix1(2, 2) = 3;

  result = matrix1.Determinant();

  ASSERT_EQ(result, 44);
}

TEST(matrixTest, InverseMatrixTest) {
  S21Matrix matrix1(3, 3), result(3, 3), matrix2(3, 3);
  matrix1(0, 0) = 5;
  matrix1(0, 1) = -1;
  matrix1(0, 2) = 1;
  matrix1(1, 0) = 2;
  matrix1(1, 1) = 3;
  matrix1(1, 2) = 4;
  matrix1(2, 0) = 1;
  matrix1(2, 1) = 0;
  matrix1(2, 2) = 3;

  result(0, 0) = 0.204545;
  result(0, 1) = 0.0681818;
  result(0, 2) = -0.159091;
  result(1, 0) = -0.0454545;
  result(1, 1) = 0.318182;
  result(1, 2) = -0.409091;
  result(2, 0) = -0.0681818;
  result(2, 1) = -0.0227273;
  result(2, 2) = 0.386364;

  matrix2 = matrix1.InverseMatrix();

  for (int i = 0; i < result.getRows(); i++) {
    for (int j = 0; j < result.getCols(); j++) {
      EXPECT_NEAR(result.getMatrixElement(i, j), matrix2.getMatrixElement(i, j),
                  0.000001);
    }
  }
}

TEST(matrixTest, s21MatrixWithDataTest) {
  S21Matrix matrix(2, 3);
  ASSERT_EQ(matrix.getRows(), 2);
  ASSERT_EQ(matrix.getCols(), 3);
  for (int i = 0; i < matrix.getRows(); i++) {
    for (int j = 0; j < matrix.getCols(); j++) {
      ASSERT_EQ(matrix.getMatrixElement(i, j), 0);
    }
  }
  matrix.SetRows(3);
  for (int j = 0; j < matrix.getCols(); j++) {
    ASSERT_EQ(matrix.getMatrixElement(2, j), 0);
  }
  matrix.SetCols(4);
  for (int i = 0; i < matrix.getRows(); i++) {
    ASSERT_EQ(matrix.getMatrixElement(i, 3), 0);
  }
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
