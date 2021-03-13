#pragma once
#include "../common/constant.h"
#include "../math/vec.h"

namespace tcalib::distortion {
struct None {
  Vec<FloatType> distort(const Vec<FloatType>& uv) const {
    return uv;
  }
  Vec<FloatType> undistort(const Vec<FloatType>& m) const {
    return m;
  }
};
}  // namespace tcalib::distortion
