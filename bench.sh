#!/bin/sh
set -o errexit
cd "$(dirname "$0")"
if [ ! -r build_o2 ]; then
    meson setup build_o2
    meson setup build_o3
    meson configure build_o2 -Doptimization=2
    meson configure build_o3 -Doptimization=3
fi
ninja -C build_o2
ninja -C build_o3
./build_o2/bench
./build_o3/bench
