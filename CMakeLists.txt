cmake_minimum_required(VERSION 3.10)
project(TinyCalib LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "--coverage")
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "--coverage")

add_subdirectory(third_party)
add_subdirectory(src)
add_subdirectory(tests)
