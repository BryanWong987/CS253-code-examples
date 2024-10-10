#include <stdio.h>
#include <math.h>

#include "structs.h"


// a struct that represents a point in two dimensions.
struct point {
    int x;
    int y;
};

//structs can be composed of other structs too.
struct rect {
    struct point p1;
    struct point p2;
};

double distance(struct point p1, struct point p2) {

    return sqrt((double)((p2.x-p1.x)*(p2.x-p1.x)) + (double)((p2.y-p1.y)*(p2.y-p1.y)));
}

void swapPointX(struct point *p1, struct point *p2) {

    int temp = (*p1).x; 
    p1->x = p2->x; 
    p2->x = temp;
}

int main(void) {
    struct point origin; //can be declared but not initialized. 
    struct point mypt = {3, 4}; //can be initialized too.

    printf("sizeof struct point: %lu\n", sizeof(struct point));

    //we can assign values to mypt using the '.' operator
    origin.x = 0;
    origin.y = 0;

    printf("origin is %d, %d\n", origin.x, origin.y);

    printf("distance between both points: %g\n", distance(mypt, origin));

    printf("mypt.x = %d\n", mypt.x);
    swapPointX(mypt, origin);
    printf("mypt.x = %d\n", mypt.x);

    //todo fix the swapping! 
}
