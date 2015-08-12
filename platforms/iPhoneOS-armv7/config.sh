#! /bin/bash

sdk=iphoneos
sdk_ver=$(xcodebuild -version -sdk ${sdk} SDKVersion)
echo "using SDK version: ${sdk_ver}"

export force_cross_compiling=yes
export cross_compiling=yes

host=armv7-apple-darwin
target=armv7-apple-darwin

export ARC=armv7

export N_SDKROOT=$(xcodebuild -version -sdk ${sdk} Path)


export CPP=$(xcodebuild -sdk ${sdk} -find cpp)
export CC=$(xcodebuild -sdk ${sdk} -find clang)
export AS=$(xcodebuild -sdk ${sdk} -find as)

export LD=$(xcodebuild -sdk ${sdk} -find ld)
export AR=$(xcodebuild -sdk ${sdk} -find ar)
export RANLIB=$(xcodebuild -sdk ${sdk} -find ranlib)

export NM=$(xcodebuild -sdk ${sdk} -find nm)
export STRIP=$(xcodebuild -sdk ${sdk} -find strip)

# export CPPFLAGS=" -D__arm__ -sysroot $N_SDKROOT  "
export CPPFLAGS=" -D__arm__ "
export CFLAGS=" -arch $ARC -isysroot $N_SDKROOT -DAPPLE -DIPHONE -D__arm__"
export LDFLAGS="  -isysroot $N_SDKROOT -arch $ARC -D__arm__ "

# export MAKELEVEL=1
