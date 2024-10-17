#ifndef THREE_D_H
#define THREE_D_H

struct threed {
    int ***array;
    int x, y, z; //the bounds of each dimension
};

typedef struct threed ThreeD;
typedef struct threed *ThreeDPtr;

/* Create a threed struct with dimensions */
ThreeDPtr CreateThreeD(int x, int y, int z);

/* properly frees the threed */
void DestroyThreeD(ThreeDPtr);

void SetVal(ThreeDPtr T, int x, int y, int z, int a);

int GetVal(ThreeDPtr T, int x, int y, int z);

#endif