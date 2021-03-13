#include <gtest/gtest.h>
#include <math/matrix.h>
#include <math/vec.h>

TEST(Matrix, Construct) {
  tcalib::Matrix mat(10, 10);
}

TEST(Matrix, Assign) {
  tcalib::Matrix mat(2, 2);
  ASSERT_FLOAT_EQ(mat(0, 0), 0.F);
  ASSERT_FLOAT_EQ(mat(1, 0), 0.F);
  ASSERT_FLOAT_EQ(mat(0, 1), 0.F);
  ASSERT_FLOAT_EQ(mat(1, 1), 0.F);
  mat(0, 0) = 1.F;
  mat(1, 0) = 2.F;
  mat(0, 1) = 3.F;
  mat(1, 1) = 4.F;
  ASSERT_FLOAT_EQ(mat(0, 0), 1.F);
  ASSERT_FLOAT_EQ(mat(1, 0), 2.F);
  ASSERT_FLOAT_EQ(mat(0, 1), 3.F);
  ASSERT_FLOAT_EQ(mat(1, 1), 4.F);
}

TEST(Matrix, MultiplyMat) {
  tcalib::Matrix mat1(2, 2);
  tcalib::Matrix mat2(2, 2);
  mat1(0, 0) = 1.F;
  mat1(1, 0) = 2.F;
  mat1(0, 1) = 3.F;
  mat1(1, 1) = 4.F;

  mat2(0, 0) = 10.F;
  mat2(1, 0) = 20.F;
  mat2(0, 1) = -30.F;
  mat2(1, 1) = 40.F;

  const auto mat = mat1 * mat2;

  ASSERT_FLOAT_EQ(mat(0, 0), -50.F);
  ASSERT_FLOAT_EQ(mat(1, 0), 100.F);
  ASSERT_FLOAT_EQ(mat(0, 1), -90.F);
  ASSERT_FLOAT_EQ(mat(1, 1), 220.F);
}

TEST(Matrix, MultiplyVec) {
  tcalib::Matrix mat1(2, 2);
  tcalib::Vec<tcalib::FloatType> vec1{-4, 1};
  mat1(0, 0) = 1.F;
  mat1(1, 0) = 2.F;
  mat1(0, 1) = 3.F;
  mat1(1, 1) = 4.F;

  const auto vec = mat1 * vec1;

  ASSERT_EQ(vec.size(), 2);
  ASSERT_FLOAT_EQ(vec[0], -2.F);
  ASSERT_FLOAT_EQ(vec[1], -8.F);
}
