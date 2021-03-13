#pragma once
#include <cassert>
#include <iostream>

#include "../math/vec.h"

namespace tcalib {

struct PinholeIntrinsic {
  float fx;
  float fy;
  float cx;
  float cy;
  float width;
  float height;
};

template <typename DistortionModel>
class Pinhole {
 public:
  Pinhole(const PinholeIntrinsic& intrinsic, const DistortionModel& distortionModel) : intrinsic_(intrinsic), distortionModel_(distortionModel) {
    assert(intrinsic_.fx > 0);
    assert(intrinsic_.fy > 0);
    assert(intrinsic_.cx > 0);
    assert(intrinsic_.cy > 0);
    assert(intrinsic_.cx < intrinsic_.width);
    assert(intrinsic_.cy < intrinsic_.height);
  }

  Vec<FloatType> project(const Vec<FloatType>& objectPoint) const {
    const auto x = objectPoint[0] / objectPoint[2];
    const auto y = objectPoint[1] / objectPoint[2];
    const auto mVec = distortionModel_.distort({x, y});
    return {
        mVec[0] * intrinsic_.fx + intrinsic_.cx,
        mVec[1] * intrinsic_.fy + intrinsic_.cy,
    };
  }

  Vec<FloatType> unproject(const Vec<FloatType>& imagePoint) const {
    const auto mx = (imagePoint[0] - intrinsic_.cx) / intrinsic_.fx;
    const auto my = (imagePoint[1] - intrinsic_.cy) / intrinsic_.fy;
    const auto xy = distortionModel_.undistort({mx, my});
    return {
        xy[0],
        xy[1],
        1.F};
  }

 private:
  PinholeIntrinsic intrinsic_;
  DistortionModel distortionModel_;
};
}  // namespace tcalib
