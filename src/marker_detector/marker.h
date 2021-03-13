#pragma once
#include <Eigen/Core>
#include <cctype>
#include <vector>

#include "../id.h"
namespace tcalib {
struct Marker {
  float size;
  MarkerId id;
  std::vector<Eigen::Vector3f> worldPoints;
};

}  // namespace tcalib
