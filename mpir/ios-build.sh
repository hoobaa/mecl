#!/bin/sh
set -e

# android : http://d.hatena.ne.jp/tmash06/20110501/1304247426
# ios     : http://onmessage.ws/wordpress/?p=802

export ARC=armv7 # ${1:-armv7}

if [ $ARC != "armv7" -a $ARC != "arm64" ]; then
    echo "not support architecture $ARC";
    exit 1;
fi

PLATFORM_DIR="/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform"
SDK_DIR="${PLATFORM_DIR}/Developer/SDKs/iPhoneOS8.4.sdk/"
TOOLCHAINS_BINDIR="${PLATFORM_DIR}/Developer/usr/bin"

sdk=iphoneos

export CC=$(xcodebuild -sdk ${sdk} -find clang)
export AR=$(xcodebuild -sdk ${sdk} -find ar)
export AS=$(xcodebuild -sdk ${sdk} -find as)
export LD=$(xcodebuild -sdk ${sdk} -find ld)
export RANLIB=$(xcodebuild -sdk ${sdk} -find ranlib)

export CFLAGS="-arch ${ARC} -isysroot ${SDK_DIR} -DAPPLE"
export LDFLAGS=""

# export CLFAGS="-arch armv7 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS8.4.sdk -DAPPLE -DIPHONE -D__arm__ -g -O2"
# export LDFLAGS="-arch armv7 -D__arm__"

PWD=`pwd`
PREFIX="${PWD}/local_iPhoneOS_${ARC}"

env |sort > env.log

./configure --srcdir=/Users/strobolights/dev/mecl/mpir --prefix=/Users/strobolights/dev/mecl/local-install/iPhoneOS-armv7 --target=armv7-apple-darwin --host=armv7-apple-darwin --enable-gmpcompat --disable-shared
# ./configure --srcdir=/Users/strobolights/dev/mecl/mpir --prefix=/Users/strobolights/dev/mecl/local-install/iPhoneOS-armv7 --target=armv7-apple-darwin --host=armv7-apple-darwin --enable-gmpcompat --disable-shared --build=x86_64-apple-darwin

make
