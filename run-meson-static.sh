rm -rf build
meson build
ninja -C build
./build/src/statically-linked

