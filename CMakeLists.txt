cmake_minimum_required(VERSION 3.10)
project(TinyCalib LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

add_subdirectory(third_party)
add_subdirectory(src)
add_subdirectory(tests)
