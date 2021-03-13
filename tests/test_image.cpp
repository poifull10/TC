#include <gtest/gtest.h>
#include <image.h>

#include <cstdlib>

TEST(GrayImage, WidthHeight) {
  tcalib::GrayImage image(9, 11);

  ASSERT_EQ(image.width(), 9);
  ASSERT_EQ(image.height(), 11);
}

TEST(GrayImage, Assign) {
  tcalib::GrayImage image(9, 11);
  image(1, 4, 3);
  ASSERT_EQ(image(1, 4), 3);
}
