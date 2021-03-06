#!/bin/bash
set -ex

build_type="Debug"
compiler_type="gcc"

usage_exit() {
  echo "Usage: $0 [-c gcc|clang] [-b Debug|Release]" 1>&2
  exit 1
}

while getopts ab:c:th OPT
do
  case $OPT in
    b)  build_type=$OPTARG ;;
    c)  compiler_type=$OPTARG ;;
    h)  usage_exit ;;
    \?) usage_exit ;;
  esac
done

set -u

git submodule update --init --recursive

# check format
python3 /build/run-clang-format/run-clang-format.py -r src tests

# build
build_space=build/$build_type-$compiler_type
mkdir -p $build_space && cd $build_space

c_compiler=""
cxx_compiler=""
gcov_tool_opt=""
if [ $compiler_type = "gcc" ]; then
  c_compiler=/usr/local/bin/gcc
  cxx_compiler=/usr/local/bin/g++
elif [ $compiler_type = "clang" ]; then
  c_compiler=/usr/bin/clang
  cxx_compiler=/usr/bin/clang++
  gcov_tool_opt="--gcov-tool ../../.ci/llvm-gcov.sh"
else
  echo "Unexpected option: " $compiler_type
  exit 1
fi

cmake ../.. -DCMAKE_BUILD_TYPE=$build_type -DCMAKE_C_COMPILER=$c_compiler -DCMAKE_CXX_COMPILER=$cxx_compiler -GNinja
ninja
./tests/TCalibTest

readonly cov_dir=tests/CMakeFiles/TCalibTest.dir
lcov -d $cov_dir -c -o coverage.info $gcov_tool_opt
lcov --remove coverage.info '/usr/include/*' '*/gtest/*' '/usr/local/*' '*/gcc/*' -o coverageFiltered.info
genhtml -o lcovHtml --num-spaces 4 -s --legend coverageFiltered.info
lcov --list coverageFiltered.info
