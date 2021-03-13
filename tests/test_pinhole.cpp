#include <camera_model/distortion.h>
#include <camera_model/pinhole.h>
#include <gtest/gtest.h>

TEST(Pinhole, None) {
  tcalib::Pinhole<tcalib::distortion::None> pinholeNone(
      tcalib::PinholeIntrinsic{10, 10, 10, 10, 20, 20},
      tcalib::distortion::None{});

  Eigen::Vector3f ans_xyz{30.1F, -17.3F, 9.1F};
  const auto uv = pinholeNone.project(ans_xyz);
  const auto xyz = pinholeNone.unproject(uv);

  ASSERT_FLOAT_EQ(xyz(0) / xyz(2), ans_xyz(0) / ans_xyz(2));
  ASSERT_FLOAT_EQ(xyz(1) / xyz(2), ans_xyz(1) / ans_xyz(2));
}
