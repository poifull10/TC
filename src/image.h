#pragma once
#include <boost/gil.hpp>
namespace tcalib {

class GrayImage {
 public:
  GrayImage(std::size_t width, std::size_t height) : data_(width, height) {
    fill_pixels(view(data_), 0);
  }
  GrayImage(const GrayImage&) = delete;
  GrayImage& operator=(const GrayImage&) = delete;

  std::uint8_t operator()(std::size_t x, std::size_t y) const {
    return const_view(data_)(x, y);
  }

  void operator()(std::size_t x, std::size_t y, std::uint8_t value) {
    view(data_)(x, y) = value;
  }

  std::size_t width() const { return const_view(data_).width(); }
  std::size_t height() const { return const_view(data_).height(); }

 private:
  boost::gil::gray8_image_t data_;
};

template <typename Image>
struct TaggedImage {
  std::size_t id;
  Image image;
};

}  // namespace tcalib