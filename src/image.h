#pragma once
#include <boost/gil.hpp>
#include <cstdint>

#include "id.h"
namespace tcalib {

class GrayImage {
 public:
  GrayImage(size_t width, size_t height) : data_(static_cast<long>(width), static_cast<long>(height)) {
    fill_pixels(view(data_), 0);
  }
  GrayImage(const GrayImage&) = delete;
  GrayImage& operator=(const GrayImage&) = delete;

  template <typename T>
  uint8_t operator()(T x, T y) const {
    return const_view(data_)(static_cast<long>(x), static_cast<long>(y));
  }

  template <typename T>
  void operator()(T x, T y, uint8_t value) {
    view(data_)(static_cast<long>(x), static_cast<long>(y)) = value;
  }

  size_t width() const {
    return static_cast<size_t>(const_view(data_).width());
  }
  size_t height() const { return static_cast<size_t>(const_view(data_).height()); }

 private:
  boost::gil::gray8_image_t data_;
};

template <typename Image>
struct TaggedImage {
  CameraId cameraId;
  Image image;
};

}  // namespace tcalib
