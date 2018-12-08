subdir('lib')

executable('statically-linked', 'main.c',
           link_with: runtimelib)
executable('use-shared-library', 'main.c',
           link_with: runtime_shared_lib)

cc = meson.get_compiler('c')

libdl = cc.find_library('dl')
executable('dynamic-library-loader', 'dlmain.c',
           dependencies: libdl)
