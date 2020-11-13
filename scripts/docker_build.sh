#!/bin/bash
readonly user_name=$USER_NAME
BUILD_TOOLKIT=1 docker build docker -t $user_name/tcalib-standard --target standard
BUILD_TOOLKIT=1 docker build docker -t $user_name/tcalib-ci --target ci
