#include <stdio.h>

struct container {
    int (*function) (void);
};

int foo(void) {
    return 4; //not needed to do anything.
}

int main(void) {

    // recall that all constructs have a location in memory. 
    int a = 4;
    printf("a's location is %p\n", &a);

    // recall that functions live in the data segment of memory.
    
    // we can see a functions address!
    printf("foo's location is %p\n", foo);

    //&foo is a pointer to foo.

    // We can store foo inside a container!

    struct container C;
    C.function = foo;

    // C.function can now be used!
    printf("calling C.function now: %d\n", C.function());
}