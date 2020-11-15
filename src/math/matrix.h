#pragma once
#include <Eigen/Core>
#include <cctype>
#include <memory>

#include "../common/constant.h"
#include "vec.h"

namespace tcalib {
class Matrix {
 public:
  Matrix(std::size_t col, std::size_t row) : mat_(col, row) {}
  ~Matrix() = default;

  FloatType& operator()(int x, int y) {
    return mat_(y, x);
  }

  FloatType operator()(int x, int y) const {
    return mat_(y, x);
  }

  Matrix operator*(const Matrix& mat) {
    Eigen::MatrixXf m = mat_ * mat.mat_;
    return Matrix(std::move(m));
  }

 private:
  Matrix(Eigen::MatrixXf&& mat) : mat_(mat) {}
  Eigen::MatrixXf mat_;
};
}  // namespace tcalib
