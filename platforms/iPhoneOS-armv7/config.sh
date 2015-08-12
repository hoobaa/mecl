#! /bin/bash

sdk=iphoneos
sdk_ver=$(xcodebuild -version -sdk ${sdk} SDKVersion)
echo "using SDK version: ${sdk_ver}"

export force_cross_compiling=yes
export cross_compiling=yes

host=armv7-apple-darwin
target=armv7-apple-darwin
# host=iPhoneOS-armv7
# target=iPhoneOS-armv7
export N_SDKROOT=$(xcodebuild -version -sdk ${sdk} Path)
# export SDK_DIR=$(xcodebuild -version -sdk ${sdk} Path)
export ARC=armv7
# export CC=$(xcodebuild -sdk ${sdk} -find clang)

# export CXX="$CC"
export CPP=$(xcodebuild -sdk ${sdk} -find cpp)
# export CPP=$(xcodebuild -sdk ${sdk} -find cpp)
export CC=$(xcodebuild -sdk ${sdk} -find clang)
# export CC=/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/usr/bin/clang
# export CXX=$(xcodebuild -sdk ${sdk} -find clang++)
export AS=$(xcodebuild -sdk ${sdk} -find as)
# export AS=/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/usr/bin/as

export LD=$(xcodebuild -sdk ${sdk} -find ld)
# export LD=/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ld
# export LD=/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/usr/bin/ld
export AR=$(xcodebuild -sdk ${sdk} -find ar)
export RANLIB=$(xcodebuild -sdk ${sdk} -find ranlib)

export NM=$(xcodebuild -sdk ${sdk} -find nm)
export STRIP=$(xcodebuild -sdk ${sdk} -find strip)

# export CPPFLAGS=" -E -arch $ARC -isysroot $SDKROOT -D__arm__"
# export CPPFLAGS="-g -arch $ARC -isysroot $SDKROOT -DAPPLE -DIPHONE -D__arm__ -E "
# export CFLAGS="-g -arch $ARC -isysroot $SDKROOT -DAPPLE -DIPHONE -D__arm__"
# export CPPFLAGS=" -sysroot $N_SDKROOT -D__arm__ "
# export CPPFLAGS=" -D__arm__ -sysroot $N_SDKROOT  "
export CPPFLAGS=" -D__arm__ "
export CFLAGS=" -arch $ARC -isysroot $N_SDKROOT -DAPPLE -DIPHONE -D__arm__"
# export CFLAGS="-arch $ARC -isysroot $SDKROOT -DAPPLE "
# export CXXFLAGS="-g -arch $ARC -isysroot $SDKROOT -DAPPLE -DIPHONE -D__arm__"
# export LDFLAGS="-arch $ARC -isysroot $SDKROOT"
export LDFLAGS="  -isysroot $N_SDKROOT -arch $ARC -D__arm__ "

# PWD=/Users/strobolights/dev/mecl/mpir
export MAKELEVEL=1
