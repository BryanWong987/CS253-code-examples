#include "threed.h"
#include "stdlib.h"
#include "stdio.h"

ThreeDPtr CreateThreeD(int x, int y, int z) {
    ThreeDPtr threedPtr = (ThreeDPtr) malloc(sizeof(ThreeD));
    threedPtr->array = (int ***) malloc(sizeof(int**) * x);
    for (int i = 0; i < x; i++) {
        threedPtr->array[i] = (int **) malloc(sizeof(int*) * y);
        for (int j = 0; j < y; j++) {
            threedPtr->array[i][j] = (int *) malloc(sizeof(int) * z); 
        }
    }
    threedPtr->x = x;
    threedPtr->y = y;
    threedPtr->z = z;
    return threedPtr;
}

void SetVal(ThreeDPtr T, int x, int y, int z, int a) {
    if (T == NULL) {
        fprintf(stderr, "Invalid index(es) detected");
    }
    T->array[x][y][z] = a;
}

int GetVal(ThreeDPtr T, int x, int y, int z) {
    return T->array[x][y][z];
}

void DestroyThreeD(ThreeDPtr T) {
    for (int i = 0; i < T->y; i++) {
        for (int j = 0; j < T->z; j++) {
            free(T->array[i][j]);
        }
        free(T->array[i]);
    }
    free(T->array);
    free(T);
}