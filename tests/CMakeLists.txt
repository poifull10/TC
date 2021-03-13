add_executable(
  TCalibTest
  main.cpp
  test_pose.cpp
  test_pinhole.cpp
  test_image.cpp
)

find_package(Eigen3 REQUIRED)

target_include_directories(TCalibTest
  PUBLIC
  $<INSTALL_INTERFACE:src>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  PRIVATE
  ${EIGEN3_INCLUDE_DIR}
)

target_link_libraries(TCalibTest gtest TCalib::TCalib)
