#!/bin/sh
set -e

# android : http://d.hatena.ne.jp/tmash06/20110501/1304247426
# ios     : http://onmessage.ws/wordpress/?p=802

# export ARC=armv7 # ${1:-armv7}
# export ARC=${1:-arm64}
export ARC=aarch64
export ARC2=arm64
# export ARC=armv7
# export ARC2=armv7

PLATFORM_DIR="/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform"
SDK_DIR="${PLATFORM_DIR}/Developer/SDKs/iPhoneOS8.4.sdk/"
TOOLCHAINS_BINDIR="${PLATFORM_DIR}/Developer/usr/bin"

sdk=iphoneos

export CC=$(xcodebuild -sdk ${sdk} -find clang)
export AR=$(xcodebuild -sdk ${sdk} -find ar)
export AS=$(xcodebuild -sdk ${sdk} -find as)
export LD=$(xcodebuild -sdk ${sdk} -find ld)
export RANLIB=$(xcodebuild -sdk ${sdk} -find ranlib)

export CFLAGS="-arch ${ARC2} -isysroot ${SDK_DIR} -DAPPLE"
export LDFLAGS=""

PWD=`pwd`
PREFIX="${PWD}/../local-install/iPhoneOS-${ARC2}"

env |sort > env.log

export PROJECT_INSTALL_DIR=$PREFIX
export PKG_CONFIG_PATH=$PROJECT_INSTALL_DIR/lib/pkgconfig ## IMPORTANT

export ATOMIC_OPS_CFLAGS="-I/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/include"
./configure --srcdir=/Users/strobolights/dev/mecl/bdwgc --prefix=/Users/strobolights/dev/mecl/local-install/iPhoneOS-${ARC2} --target=${ARC}-apple-darwin --host=${ARC}-apple-darwin --enable-gmpcompat --disable-shared 
# --with-libatomic-ops=/Users/strobolights/dev/mecl/local-install/iPhoneOS-${ARC2}/lib

make
