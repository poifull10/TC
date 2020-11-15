#pragma once
#include <array>
#include <initializer_list>
#include <vector>
namespace tcalib {

template <typename T>
struct Vec {
  std::vector<T> data;
  Vec(std::vector<T>& data) : data(data) {
  }
  Vec(std::initializer_list<T> init) {
    for (const auto& e : init) {
      data.emplace_back(e);
    }
  }
  std::size_t size() const { return data.size(); }
  T& operator[](std::size_t i) { return data[i]; }
  T operator[](std::size_t i) const { return data[i]; }
};
}  // namespace tcalib
