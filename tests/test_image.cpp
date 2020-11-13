#include <gtest/gtest.h>
#include <image.h>

TEST(GrayImage, Construct) {
  tcalib::GrayImage image(9, 11);

  ASSERT_EQ(image.width(), 9);
  ASSERT_EQ(image.height(), 11);
}
