#pragma once
#include <Eigen/Core>
#include <Eigen/Geometry>

namespace tcalib {

class Pose {
 public:
  Pose(const Eigen::Vector3f& translation, const Eigen::Quaternionf& quaternion) : translation_(translation), quaternion_(quaternion) {
  }

  Pose(const Eigen::Matrix4f& mat) {
    Eigen::Matrix3f R = Eigen::Matrix3f::Zero();
    for (auto h = 0; h < 3; h++) {
      for (auto w = 0; w < 3; w++) {
        R(h, w) = mat(h, w);
      }
    }
    Eigen::Quaternionf q(R);
    Eigen::Vector3f translation{mat(0, 3), mat(1, 3), mat(2, 3)};
    translation_ = std::move(translation);
    quaternion_ = std::move(q);
  }

  float tx() const { return translation_.x(); }
  float ty() const { return translation_.y(); }
  float tz() const { return translation_.z(); }
  float rx() const { return quaternion_.x(); }
  float ry() const { return quaternion_.y(); }
  float rz() const { return quaternion_.z(); }
  float rw() const { return quaternion_.w(); }

  Eigen::Matrix4f matrix() const {
    Eigen::Matrix3f R(quaternion_);
    Eigen::Matrix4f mat = Eigen::Matrix4f::Identity();
    for (auto h = 0; h < 3; h++) {
      for (auto w = 0; w < 3; w++) {
        mat(h, w) = R(h, w);
      }
    }
    mat(0, 3) = tx();
    mat(1, 3) = ty();
    mat(2, 3) = tz();
    return mat;
  }

  Pose operator*(const Pose& pose) const {
    auto mat = matrix() * pose.matrix();
    return Pose(mat);
  }

 private:
  Eigen::Vector3f translation_;
  Eigen::Quaternionf quaternion_;
};

}  // namespace tcalib
