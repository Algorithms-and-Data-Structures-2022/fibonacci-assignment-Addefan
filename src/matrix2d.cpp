#include "assignment/matrix2d.hpp"

namespace assignment {

  Matrix2x2 matrix_multiply(const Matrix2x2& left, const Matrix2x2& right) {

    Matrix2x2 res;

    // вычисляем значения на первой строке
    res[0][0] = left[0][0] * right[0][0] + left[0][1] * right[1][0];
    res[0][1] = left[0][0] * right[0][1] + left[0][1] * right[1][1];

    // вычисляем значения на второй строке
    res[1][0] = left[1][0] * right[0][0] + left[1][1] * right[1][0];
    res[1][1] = left[1][0] * right[0][1] + left[1][1] * right[1][1];

    return res;
  }

  Matrix2x2 matrix_power(Matrix2x2 matrix, int power) {

    Matrix2x2 res = IdentityMatrix;  // единичная матрица

    if (power == 0) {
      return res;
    }
    if (power % 2 == 1) {
      return matrix_multiply(matrix, matrix_power(matrix, power - 1));
    }
    Matrix2x2 temp = matrix_power(matrix, power / 2);
    return matrix_multiply(temp, temp);
  }

}  // namespace assignment