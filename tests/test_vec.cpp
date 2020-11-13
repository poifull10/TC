#include <gtest/gtest.h>
#include <math/vec.h>

#include <array>

TEST(Vec, Construct) {
  tcalib::Vec<float, 3> vec{1.F, 2.F, 3.F};
  ASSERT_FLOAT_EQ(vec[0], 1.F);
  ASSERT_FLOAT_EQ(vec[1], 2.F);
  ASSERT_FLOAT_EQ(vec[2], 3.F);

  vec[1] = 13.2F;
  ASSERT_FLOAT_EQ(vec[0], 1.F);
  ASSERT_FLOAT_EQ(vec[1], 13.2F);
  ASSERT_FLOAT_EQ(vec[2], 3.F);
}

TEST(Vec, Assign) {
  tcalib::Vec<float, 3> vec{1.F, 2.F, 3.F};
  vec[1] = 13.2F;
  vec[2] = -3.7F;
  ASSERT_FLOAT_EQ(vec[0], 1.F);
  ASSERT_FLOAT_EQ(vec[1], 13.2F);
  ASSERT_FLOAT_EQ(vec[2], -3.7F);
}
