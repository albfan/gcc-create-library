subdir('lib')

executable('statically-linked', 'main.c',
           link_with: runtimelib)
executable('use-shared-library', 'main.c',
           link_with: runtime_shared_lib)
