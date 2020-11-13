#pragma once
#include <array>
#include <initializer_list>
namespace tcalib {

template <typename T, int N>
struct Vec {
  std::array<T, N> data;
  Vec(std::array<T, N>& data) : data(data) {
  }
  Vec(std::initializer_list<T> init) {
    int cnt = 0;
    for (const auto& e : init) {
      data[cnt++] = e;
    }
  }
  T& operator[](std::size_t i) { return data[i]; }
};
}  // namespace tcalib
