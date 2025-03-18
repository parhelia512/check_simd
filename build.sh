#!/bin/bash

# Copyright (c) 2024 Alex313031.

YEL='\033[1;33m' # Yellow
CYA='\033[1;96m' # Cyan
RED='\033[1;31m' # Red
GRE='\033[1;32m' # Green
c0='\033[0m' # Reset Text
bold='\033[1m' # Bold Text
underline='\033[4m' # Underline Text

# Error handling
yell() { echo "$0: $*" >&2; }
die() { yell "$*"; exit 111; }
try() { "$@" || die "${RED}Failed $*"; }

# --help
displayHelp () {
	printf "\n" &&
	printf "${bold}${GRE}Script to build check_simd for POSIX OSes.${c0}\n" &&
	printf "${bold}${YEL}  Use the --release flag to make a release build.${c0}\n" &&
	printf "${bold}${YEL}  Use the --debug flag to make a debugging build.${c0}\n" &&
	printf "${bold}${YEL}  Use the --clean flag to clean the out directory.${c0}\n" &&
	printf "${bold}${YEL}  --help or -h shows this help.${c0}\n" &&
	printf "\n"
}
case $1 in
	--help) displayHelp; exit 0;;
esac
case $1 in
	-h) displayHelp; exit 0;;
esac

export PATH=./buildtools:$PATH

buildRelease () {
  printf "${bold}${GRE}Building all targets...${bold}${CYA}\n"
  mkdir -p ./out &&
  gn gen out/ &&
  ninja -C out/ all &&
  printf "\n${bold}${GRE}Done!\n"
}
case $1 in
	--release) buildRelease; exit 0;;
esac

buildDebug () {
  printf "${bold}${GRE}Building a debug build...${bold}${CYA}\n"
  mkdir -p ./out &&
  gn gen out/ &&
  #gcc $COMMON_DEBUG_CFLAGS -DSTANDALONE logger.cc -o ./out/logger.obj &&
  #g++ $COMMON_DEBUG_CFLAGS logger.cc check_simd.cc -o ./out/check_simd.obj
  #ldd -v $COMMON_DEBUG_CFLAGS logger.cc check_simd.cc -o ./out/check_simd.debug
  #ldd $COMMON_DEBUG_LDFLAGS ./out/logger.obj ./out/check_simd.obj -o ./out/check_simd.debug
  ninja -v -C out/ all hello_all &&
  printf "\n${bold}${GRE}Done!\n"
}
case $1 in
	--debug) buildDebug; exit 0;;
esac

cleanBuild () {
  rm -r -v ./out/*
}
case $1 in
	--clean) cleanBuild; exit 0;;
esac

displayHelp

exit 0
