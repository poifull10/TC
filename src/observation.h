#pragma once
#include <set>
#include <vector>

#include "common/constant.h"
#include "id.h"
#include "math/vec.h"

namespace tcalib {
struct Observation {
  CameraId cameraId;
  MarkerId markerId;
  std::vector<Vec<FloatType>> worldPoints;
  std::vector<Vec<FloatType>> cameraObservations;
};
}  // namespace tcalib
