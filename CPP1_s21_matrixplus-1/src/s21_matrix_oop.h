#ifndef S21_MATRIX_OOP_H_
#define S21_MATRIX_OOP_H_

#include <math.h>

#include <cstring>
#include <iostream>

class S21Matrix {
 private:
  // Attributes
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated

 public:
  S21Matrix();   // Default constructor
  ~S21Matrix();  // Destructor
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  double& operator()(int row, int col);
  double& operator()(int row, int col) const;
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(double num);
  bool operator==(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);

  void delete_matrix();
  void create_matrix();
  void CopyValues(const S21Matrix& other);
  void SetCols(int cols);
  int getCols() const;
  void SetRows(int rows);
  int getRows() const;
  double getMatrixElement(int i, int j) const;
  S21Matrix Minor(int row, int col);
};

#endif  // S21_MATRIX_OOP_H_