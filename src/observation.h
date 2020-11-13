#pragma once
#include <set>
#include <vector>

#include "common/constant.h"
#include "math/vec.h"

namespace tcalib {
struct Observation {
  std::vector<Vec<FloatType, 3>> worldPoints;
  std::set<std::size_t, std::vector<Vec<FloatType, 2>>> cameraObservations;
};
}  // namespace tcalib
