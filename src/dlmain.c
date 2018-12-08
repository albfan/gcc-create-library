#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

// Note, no headers are included

void* getFunctionPointer(void* lib, const char* funcName) {
 //
 // Get the function pointer to the function
    void* fptr = dlsym(lib, funcName);
    if (!fptr) {
      fprintf(stderr, "Could not get function pointer for %s\n  error is: %s\n\n", funcName, dlerror());
      return NULL;
    }
    return fptr;
}

int main(int argc, char* argv[]) {

 //
 // Declare the function pointers:
    void (*fptr_null      )(int);
    void (*fptr_setSummand)(int);
    int  (*fptr_add       )(int);


 //
 // Open the dynamic library
    void* runtime_lib = dlopen("libruntime.so",  RTLD_LAZY | RTLD_GLOBAL);

    if (!runtime_lib) {
     //
     // Apparently, the library could not be opened
        fprintf(stderr, "Could not open libruntime.so\n");
        exit(1);
    }


 //
 // Get the pointers to the functions within the library:
 //
 //     Function doesNotExist does not exist, demonstrate
 //     calling dlerror()
 //
    fptr_null       = getFunctionPointer(runtime_lib, "doesNotExist");
    fptr_setSummand = getFunctionPointer(runtime_lib, "setSummand"  );
    fptr_add        = getFunctionPointer(runtime_lib, "add"         );


 //
 // Call the function via the function pointer
 //
    fptr_setSummand(42);

    int result = fptr_add(7);

    printf("Result: %d\n", result);

}

