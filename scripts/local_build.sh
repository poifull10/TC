#!/bin/bash
set -ex

readonly user_name=$USER_NAME

usage_exit() {
  echo "Usage: $0 [-c gcc|clang] [-b Debug|Release]" 1>&2
  exit 1
}

while getopts b:c:h OPT
do
  case $OPT in
    b)  build_type=$OPTARG ;;
    c)  compiler_type=$OPTARG ;;
    h)  usage_exit ;;
    \?) usage_exit ;;
  esac
done

set -u

docker run --rm -v $PWD:$PWD -w $PWD -it $user_name/tcalib-ci .ci/build.sh -c $compiler_type -b $build_type
