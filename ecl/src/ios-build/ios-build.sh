#!/bin/sh
set -e

# android : http://d.hatena.ne.jp/tmash06/20110501/1304247426
# ios     : http://onmessage.ws/wordpress/?p=802

# export ARC=armv7 # ${1:-armv7}
# export ARC=${1:-arm64}
export ARC=aarch64
export ARC2=arm64

PLATFORM_DIR="/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform"
N_SDK_DIR="${PLATFORM_DIR}/Developer/SDKs/iPhoneOS8.4.sdk/"
TOOLCHAINS_BINDIR="${PLATFORM_DIR}/Developer/usr/bin"

sdk=iphoneos

export CC=$(xcodebuild -sdk ${sdk} -find clang)
export AR=$(xcodebuild -sdk ${sdk} -find ar)
export AS=$(xcodebuild -sdk ${sdk} -find as)
export LD=$(xcodebuild -sdk ${sdk} -find ld)
export RANLIB=$(xcodebuild -sdk ${sdk} -find ranlib)

PWD=`pwd`
PREFIX=/Users/strobolights/dev/mecl/local-install/iPhoneOS-${ARC2}
# PREFIX=/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64/

export CFLAGS=" -arch ${ARC2} -isysroot ${N_SDK_DIR} -DAPPLE -I$PREFIX/include"
# export LDFLAGS=" -L$PREFIX/lib "
export LDFLAGS="  -isysroot ${N_SDK_DIR} -arch ${ARC2} -D__arm__ -L$PREFIX/lib  "

env |sort > env.log

# ecl_to_run=/Users/strobolights/dev/mecl/local-install/host64/bin/ecl

../configure --srcdir=/Users/strobolights/dev/mecl/ecl/src --prefix=/Users/strobolights/dev/mecl/local-install/iPhoneOS-${ARC2} --target=${ARC}-apple-darwin --host=${ARC}-apple-darwin --disable-shared --enable-libatomic=system --with-system-behm --enable-boehm=system

# ./configure --srcdir=/Users/strobolights/dev/mecl/ecl/src --prefix=/Users/strobolights/dev/mecl/local-install/iPhoneOS-arm64 --target=aarch64-apple-darwin --host=aarch64-apple-darwin --disable-shared --build=x86_64-apple-darwin

make
