#pragma once
#include <Eigen/Core>
#include <set>
#include <vector>

#include "id.h"

namespace tcalib {
struct Observation {
  CameraId cameraId;
  MarkerId markerId;
  std::vector<Eigen::Vector3f> worldPoints;
  std::vector<Eigen::Vector2f> cameraObservations;
};
}  // namespace tcalib
