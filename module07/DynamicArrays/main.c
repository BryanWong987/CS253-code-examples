#include <stdlib.h>
#include <stdio.h>

// allocates a portion of a two dimensional array using malloc
int main(void) {

    int n = 8;
    int m = 2;

    int **twoD = (int **) malloc(sizeof(int *) * n);
    twoD[0] = (int *) malloc(sizeof(int) * m);

    free(twoD[0]);
    free(twoD);
    
    return 0;
}