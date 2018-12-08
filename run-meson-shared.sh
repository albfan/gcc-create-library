rm -rf build
meson build
ninja -C build

./build/src/use-shared-library
# If you want to see how it locates directly so file
#LD_DEBUG=files ./build/src/use-shared-library

