#include <string.h>
#include <stdlib.h>

int main(void) {

    char *myString = (char *) malloc(sizeof(char) * strlen("hello"));
    //reassigns the pointer.
    myString = "hello";
    free(myString); //error

    //use strcpy instead
    return 0;
}