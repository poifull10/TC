#pragma once
#include <memory>

#include "../image.h"
#include "../observation.h"
#include "marker.h"

namespace tcalib {

class AprilTagDetector {
  class Impl;

 public:
  AprilTagDetector(const std::vector<Marker>& markers);
  ~AprilTagDetector();

  Observation operator()(const std::vector<std::shared_ptr<TaggedImage<GrayImage>>>& syncImages);

 private:
  std::unique_ptr<Impl> impl_;
};

}  // namespace tcalib
