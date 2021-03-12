#pragma once
#include <Eigen/Geometry>

#include "matrix.h"
#include "vec.h"

namespace tcalib {

class Pose {
 public:
  Pose(const Vec<FloatType>& translation, const Vec<FloatType>& quaternion) : translation_(translation), quaternion_(quaternion) {
    assert(translation_.size() == 3);
    assert(quaternion_.size() == 4);
  }

  Pose(const Matrix& mat) {
    assert(mat.cols() == 4);
    assert(mat.rows() == 4);
    Eigen::Matrix<FloatType, 3, 3> R = Eigen::Matrix<FloatType, 3, 3>::Zero();
    for (auto h = 0; h < 3; h++) {
      for (auto w = 0; w < 3; w++) {
        R(h, w) = mat(w, h);
      }
    }
    Eigen::Quaternionf q(R);
    Vec<FloatType> translation{mat(3, 0), mat(3, 1), mat(3, 2)};
    Vec<FloatType> quaternion{q.x(), q.y(), q.z(), q.w()};
    translation_ = translation;
    quaternion_ = quaternion;
  }

  FloatType tx() const { return translation_[0]; }
  FloatType ty() const { return translation_[1]; }
  FloatType tz() const { return translation_[2]; }
  FloatType rx() const { return quaternion_[0]; }
  FloatType ry() const { return quaternion_[1]; }
  FloatType rz() const { return quaternion_[2]; }
  FloatType rw() const { return quaternion_[3]; }

  Matrix matrix() const {
    Eigen::Matrix3f R(Eigen::Quaternionf(rw(), rx(), ry(), rz()));
    Matrix mat(4, 4);
    for (auto h = 0; h < 3; h++) {
      for (auto w = 0; w < 3; w++) {
        mat(w, h) = R(h, w);
      }
    }
    mat(0, 3) = tx();
    mat(1, 3) = ty();
    mat(2, 3) = tz();
    mat(3, 3) = 1;
    return mat;
  }

  Pose operator*(const Pose& pose) const {
    auto mat = matrix() * pose.matrix();
    return Pose(mat);
  }

 private:
  Vec<FloatType> translation_;
  Vec<FloatType> quaternion_;
};

}  // namespace tcalib
