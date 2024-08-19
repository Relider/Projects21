#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(3), cols_(3) { create_matrix(); }

void S21Matrix::create_matrix() {
  this->matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; i++) {
    this->matrix_[i] = new double[cols_]();
  }
}

S21Matrix::~S21Matrix() { delete_matrix(); }

void S21Matrix::delete_matrix() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::invalid_argument("rows or columns equal or less 0");
  }
  create_matrix();
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    delete_matrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    create_matrix();
    CopyValues(other);
  }
  return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix res_matrix(rows_, cols_);
  res_matrix = *this;
  res_matrix.SumMatrix(other);
  return res_matrix;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix res_matrix(rows_, cols_);
  res_matrix = *this;
  res_matrix.SubMatrix(other);
  return res_matrix;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix res_matrix(rows_, cols_);
  res_matrix = *this;
  res_matrix.MulMatrix(other);
  return res_matrix;
}

S21Matrix S21Matrix::operator*(double num) {
  S21Matrix res_matrix(rows_, cols_);
  res_matrix = *this;
  res_matrix.MulNumber(num);
  return res_matrix;
}

S21Matrix operator*(double num, S21Matrix& matrix) { return matrix * num; }

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

double& S21Matrix::operator()(int row, int col) {
  if (row < 0 || col < 0 || row >= rows_ || col >= cols_) {
    throw std::out_of_range("InvalidIndexError: Index is out of range");
  }

  return matrix_[row][col];
}

double& S21Matrix::operator()(int row, int col) const {
  if (row < 0 || col < 0 || row >= rows_ || col >= cols_) {
    throw std::out_of_range("InvalidIndexError: Index is out of range");
  }

  return matrix_[row][col];
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  if (this->matrix_ == nullptr) {
    throw std::bad_alloc();
  }
  bool result = false;
  if (rows_ != other.rows_ && cols_ != other.cols_) {
  } else {
    result = true;
    for (int i = 0; i < rows_ && result == true; i++) {
      for (int j = 0; j < cols_ && result == true; j++) {
        if (matrix_[i][j] != other.matrix_[i][j]) {
          result = false;
        }
      }
    }
  }
  return result;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (this->matrix_ == nullptr) {
    throw std::bad_alloc();
  }
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::exception();
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] += other.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (this->matrix_ == nullptr) {
    throw std::bad_alloc();
  }
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::exception();
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] -= other.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  if (this->matrix_ == nullptr) {
    throw std::bad_alloc();
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (this->matrix_ == nullptr) {
    throw std::bad_alloc();
  }
  if (cols_ != other.rows_) {
    throw std::exception();
  }
  S21Matrix matrix_mul(rows_, other.cols_);
  for (int i = 0; i < matrix_mul.rows_; i++) {
    for (int j = 0; j < matrix_mul.cols_; j++) {
      for (int k = 0; k < cols_; k++) {
        matrix_mul.matrix_[i][j] = matrix_mul.matrix_[i][j] +
                                   (this->matrix_[i][k] * other.matrix_[k][j]);
      }
    }
  }
  *this = matrix_mul;
}

S21Matrix S21Matrix::Transpose() {
  if (this->matrix_ == nullptr) {
    throw std::bad_alloc();
  }
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[j][i] = matrix_[i][j];
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (this->matrix_ == nullptr) {
    throw std::bad_alloc();
  }
  if (rows_ != cols_) {
    throw std::exception();
  }
  S21Matrix result(cols_, rows_);
  if (rows_ == 1) {
    result.matrix_[0][0] = matrix_[0][0];
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        S21Matrix minor(Minor(i, j));
        result.matrix_[i][j] = pow(-1, i + j) * minor.Determinant();
      }
    }
  }
  return result;
}

S21Matrix S21Matrix::Minor(int row, int col) {
  S21Matrix minor(rows_ - 1, cols_ - 1);
  for (int i = 0, minor_row = 0; i < rows_; i++) {
    if (i != row) {
      for (int j = 0, minor_col = 0; j < cols_; j++) {
        if (j != col) {
          minor.matrix_[minor_row][minor_col] = matrix_[i][j];
          minor_col++;
        }
      }
      minor_row++;
    }
  }

  return minor;
}

double S21Matrix::Determinant() {
  if (this->matrix_ == nullptr) {
    throw std::bad_alloc();
  }
  if (rows_ != cols_) {
    throw std::exception();
  }
  double result = 0;
  if (rows_ == 1) {
    result = matrix_[0][0];
  } else {
    if (rows_ == 2) {
      result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
    } else {
      for (int i = 0; i < cols_; i++) {
        S21Matrix minor(Minor(0, i));
        result += pow(-1, i) * matrix_[0][i] * minor.Determinant();
      }
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (this->matrix_ == nullptr) {
    throw std::bad_alloc();
  }
  double determinant = this->Determinant();
  if (fabs(determinant) < 1e-7) {
    throw std::exception();
  }
  S21Matrix result = this->Transpose().CalcComplements();
  result.MulNumber(1.0 / determinant);
  return result;
}

void S21Matrix::CopyValues(const S21Matrix& other) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

int S21Matrix::getRows() const { return rows_; }

int S21Matrix::getCols() const { return cols_; }

double S21Matrix::getMatrixElement(int i, int j) const { return matrix_[i][j]; }

void S21Matrix::SetRows(int rows) {
  if (rows <= 0) {
    throw std::invalid_argument(
        "SetRowsError: The number of rows cannot be less than 1");
  }
  S21Matrix result(rows, cols_);
  int new_row = rows < rows_ ? rows : rows_;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (i < new_row) {
        result.matrix_[i][j] = matrix_[i][j];
      } else {
        result.matrix_[i][j] = 0;
      }
    }
  }
  *this = result;
}

void S21Matrix::SetCols(int cols) {
  if (cols <= 0) {
    throw std::invalid_argument(
        "SetColsError: The number of cols cannot be less than 1");
  }
  S21Matrix result(rows_, cols);
  int new_col = cols < cols_ ? cols : cols_;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (i < new_col) {
        result.matrix_[i][j] = matrix_[i][j];
      } else {
        result.matrix_[i][j] = 0;
      }
    }
  }
  *this = result;
}
