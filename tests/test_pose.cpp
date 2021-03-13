#include <gtest/gtest.h>
#include <math/pose.h>

TEST(Pose, Construct) {
  tcalib::Pose pose({0, 0, 0}, {0, 0, 0, 1});
}

TEST(Pose, Multiply) {
  tcalib::Matrix mat(4, 4);
  mat(0, 0) = -0.5610206F;
  mat(1, 0) = -0.7184630F;
  mat(2, 0) = -0.4111774F;
  mat(0, 1) = 0.4111774F;
  mat(1, 1) = -0.6729603F;
  mat(2, 1) = 0.6148639F;
  mat(0, 2) = -0.7184630F;
  mat(1, 2) = 0.1758844F;
  mat(2, 2) = 0.6729603F;
  mat(3, 0) = 10.0F;
  mat(3, 1) = 11.0F;
  mat(3, 2) = 12.0F;

  tcalib::Pose pose(mat);

  ASSERT_FLOAT_EQ(pose.tx(), 10.0F);
  ASSERT_FLOAT_EQ(pose.ty(), 11.0F);
  ASSERT_FLOAT_EQ(pose.tz(), 12.0F);
  ASSERT_FLOAT_EQ(pose.rx(), -0.3312776F);
  ASSERT_FLOAT_EQ(pose.ry(), 0.2318943F);
  ASSERT_FLOAT_EQ(pose.rz(), 0.8524877F);
  ASSERT_FLOAT_EQ(pose.rw(), 0.3312776F);
}
