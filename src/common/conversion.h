#pragma once
#include <opencv2/opencv.hpp>

#include "../image.h"
namespace tcalib {

cv::Mat toMat(const GrayImage& image) {
  cv::Mat mat(image.height(), image.width(), CV_8UC1);
  for (auto iy = 0; iy < image.height(); iy++) {
    for (auto ix = 0; ix < image.width(); ix++) {
      mat.at<std::uint8_t>(iy, ix) = image(ix, iy);
    }
  }
  return mat;
}
}  // namespace tcalib
