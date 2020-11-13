add_executable(
  TCalibTest
  main.cpp
)

target_link_libraries(TCalibTest gtest TCalib::TCalib)
