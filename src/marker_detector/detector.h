#pragma once
#include <memory>
#include <unordered_map>

#include "../image.h"
#include "../observation.h"
#include "marker.h"

namespace tcalib {

class AprilTagDetector {
  class Impl;

 public:
  AprilTagDetector(const std::unordered_map<std::size_t, Marker>& markers);
  ~AprilTagDetector();

  std::vector<Observation> operator()(const std::vector<std::shared_ptr<TaggedImage<GrayImage>>>& syncImages);

 private:
  std::unique_ptr<Impl> impl_;
};

}  // namespace tcalib
