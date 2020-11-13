#pragma once
#include "../common/constant.h"
#include "../math/vec.h"

namespace tcalib::distortion {
struct None {
  Vec<FloatType, 2> distort(const Vec<FloatType, 2>& uv) const {
    return uv;
  }
  Vec<FloatType, 2> undistort(const Vec<FloatType, 2>& m) const {
    return m;
  }
};
}  // namespace tcalib::distortion
