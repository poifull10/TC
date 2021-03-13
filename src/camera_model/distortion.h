#pragma once
#include <Eigen/Core>

namespace tcalib::distortion {
struct None {
  Eigen::Vector2f distort(const Eigen::Vector2f& uv) const {
    return uv;
  }
  Eigen::Vector2f undistort(const Eigen::Vector2f& m) const {
    return m;
  }
};
}  // namespace tcalib::distortion
