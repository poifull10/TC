#pragma once
#include <opencv2/opencv.hpp>

#include "../image.h"
namespace tcalib {

inline cv::Mat toMat(const GrayImage& image) {
  cv::Mat mat(static_cast<int>(image.height()), static_cast<int>(image.width()), CV_8UC1);
  for (auto iy = 0; iy < static_cast<int>(image.height()); iy++) {
    for (auto ix = 0; ix < static_cast<int>(image.width()); ix++) {
      mat.at<std::uint8_t>(iy, ix) = image(ix, iy);
    }
  }
  return mat;
}
}  // namespace tcalib
