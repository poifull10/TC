add_executable(
  TCalibTest
  main.cpp
  test_vec.cpp
  test_pinhole.cpp
)

target_link_libraries(TCalibTest gtest TCalib::TCalib)
