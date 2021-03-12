#include "detector.h"

#include <opencv2/aruco.hpp>
#include <opencv2/opencv.hpp>

#include "../common/conversion.h"

namespace tcalib {
class AprilTagDetector::Impl {
 public:
  Impl(const std::unordered_map<std::size_t, Marker>& markers) : markers_(markers) {}
  ~Impl() = default;

  std::vector<Observation> operator()(const std::vector<std::shared_ptr<TaggedImage<GrayImage>>>& syncImages) {
    std::vector<Observation> observations;
    for (const auto& imagePtr : syncImages) {
      Observation observation{};
      const auto matImage = toMat(imagePtr->image);
      std::vector<int> markerIds;
      std::vector<std::vector<cv::Point2f>> markerCorners, rejectedCandidates;
      auto parameters = cv::aruco::DetectorParameters::create();
      auto dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_APRILTAG_36h11);
      cv::aruco::detectMarkers(matImage, dictionary, markerCorners, markerIds, parameters, rejectedCandidates);
      for (int markerIdInt : markerIds) {
        const auto marker = markers_.at(markerIdInt);
        observation.markerId = marker.id;
        observation.cameraId = imagePtr->cameraId;
        for (auto imagePoint : markerCorners[markerIdInt]) {
          observation.cameraObservations.emplace_back(Vec<FloatType>{imagePoint.x, imagePoint.y});
        }
        for (auto objectPoint : markers_.at(marker.id()).worldPoints) {
          observation.worldPoints.emplace_back(objectPoint);
        }
      }
      if (!observation.cameraObservations.empty()) {
        observations.emplace_back(observation);
      }
    }
    return observations;
  }

  std::unordered_map<std::size_t, Marker> markers_;
};

AprilTagDetector::AprilTagDetector(const std::unordered_map<std::size_t, Marker>& markers) : impl_{std::make_unique<Impl>(markers)} {
}

AprilTagDetector::~AprilTagDetector() {
}

std::vector<Observation> AprilTagDetector::operator()(const std::vector<std::shared_ptr<TaggedImage<GrayImage>>>& syncImages) {
  return (*impl_)(syncImages);
}

}  // namespace tcalib
