#pragma once
#include <cctype>

#include "../common/constant.h"
#include "../id.h"
#include "../math/vec.h"

namespace tcalib {
struct Marker {
  float size;
  MarkerId id;
  std::vector<Vec<FloatType>> worldPoints;
};

}  // namespace tcalib
