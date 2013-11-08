#!/bin/bash
make host64.ecl  > /tmp/log.host64.ecl  2>&1 &

make host.ecl    > /tmp/log.host.ecl    2>&1

make ios-univ    > /tmp/log.ios.ecl     2>&1 &
export ANDROID_NDK_ROOT=/Applications/adt/ndk; make android.ecl > /tmp/log.android.ecl 2>&1 &
