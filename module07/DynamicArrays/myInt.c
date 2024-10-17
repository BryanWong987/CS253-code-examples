#include <stdlib.h>
#include <stdio.h>

int main(void) {

    int n = 10; //the number of ints.
    int i; //for later

    int *myInts = (int *) malloc(sizeof(int) * n);

    for(i = 0; i < n; i++) {
        myInts[i] = i;
    }

    for(i = 0; i < n; i++) {
        printf("%d ", myInts[i]);
    }

    printf("\n");

    free(myInts);
    
    return 0;
}