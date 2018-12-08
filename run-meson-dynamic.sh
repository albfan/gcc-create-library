rm -rf build
meson build
ninja -C build
LD_LIBRARY_PATH=$(pwd)/build/src/lib ./build/src/dynamic-library-loader

