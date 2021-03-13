#pragma once
#include <array>
#include <initializer_list>
#include <vector>
namespace tcalib {

template <typename T>
class Vec {
 public:
  Vec() = default;
  Vec(std::vector<T>& data) : data_(data) {
  }
  Vec(std::size_t size) : data_(size) {
  }
  Vec(std::initializer_list<T> init) {
    for (const auto& e : init) {
      data_.emplace_back(e);
    }
  }

  std::size_t size() const { return data_.size(); }
  T& operator[](std::size_t i) { return data_[i]; }
  T operator[](std::size_t i) const { return data_[i]; }

 private:
  std::vector<T> data_;
};
}  // namespace tcalib
