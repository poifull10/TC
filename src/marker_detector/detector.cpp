#include "detector.h"

#include <opencv2/aruco.hpp>
#include <opencv2/opencv.hpp>

#include "../common/conversion.h"

namespace tcalib {
class AprilTagDetector::Impl {
 public:
  Impl(const std::vector<Marker>& markers) : markers_(markers) {}
  ~Impl() = default;

  Observation operator()(const std::vector<std::shared_ptr<TaggedImage<GrayImage>>>& syncImages) {
    Observation observation;
    for (const auto imagePtr : syncImages) {
      const auto matImage = toMat(imagePtr->image);
      std::vector<int> markerIds;
      std::vector<std::vector<cv::Point2f>> markerCorners, rejectedCandidates;
      auto parameters = cv::aruco::DetectorParameters::create();
      auto dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_APRILTAG_36h11);
      cv::aruco::detectMarkers(matImage, dictionary, markerCorners, markerIds, parameters, rejectedCandidates);
    }
    return Observation{};
  }

  std::vector<Marker> markers_;
};

AprilTagDetector::AprilTagDetector(const std::vector<Marker>& markers) : impl_{std::move(std::make_unique<Impl>(markers))} {
}

AprilTagDetector::~AprilTagDetector() {
}

Observation AprilTagDetector::operator()(const std::vector<std::shared_ptr<TaggedImage<GrayImage>>>& syncImages) {
  return (*impl_)(syncImages);
}

}  // namespace tcalib
