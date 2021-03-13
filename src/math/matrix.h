#pragma once
#include <Eigen/Core>
#include <cctype>
#include <memory>

#include "../common/constant.h"
#include "vec.h"

namespace tcalib {
class Matrix {
 public:
  Matrix(std::size_t row, std::size_t col) : mat_(Eigen::MatrixXf::Zero(row, col)) {}
  ~Matrix() = default;

  FloatType& operator()(int y, int x) {
    return mat_(y, x);
  }

  FloatType operator()(int y, int x) const {
    return mat_(y, x);
  }

  Matrix operator*(const Matrix& mat) {
    Eigen::MatrixXf m = mat_ * mat.mat_;
    return Matrix(std::move(m));
  }

  Vec<FloatType> operator*(const Vec<FloatType>& vec) {
    assert(mat_.cols() == vec.size());
    const Eigen::VectorXf v = Eigen::Map<const Eigen::VectorXf>(vec.data(), vec.size());
    const Eigen::VectorXf v2 = mat_ * v;

    Vec<FloatType> output(mat_.rows());
    for (auto i = 0; i < mat_.rows(); i++) {
      output[i] = v2(i);
    }
    return output;
  }

  size_t cols() const { return mat_.cols(); }
  size_t rows() const { return mat_.rows(); }

  Matrix transpose() const {
    Eigen::MatrixXf tmat = mat_.transpose();
    return Matrix(std::move(tmat));
  }

 private:
  Matrix(Eigen::MatrixXf&& mat) : mat_(mat) {}
  Eigen::MatrixXf mat_;
};
}  // namespace tcalib
