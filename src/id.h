#pragma once
#include <cctype>

namespace tcalib {

struct CameraId {
  size_t id;
  size_t operator()() const { return id; }
};
struct MarkerId {
  size_t id;
  size_t operator()() const { return id; }
};

}  // namespace tcalib
