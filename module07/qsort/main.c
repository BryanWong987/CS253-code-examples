#include <stdio.h>
#include <stdlib.h>


#define ARRAY_SIZE  6
#define RANGE       100

struct person {
    int age;
    int height;
};

typedef struct person Person;
typedef struct person *PersonPtr;

int compareAgeAscending(const void *a, const void *b) {
    
    if (a == NULL && b != NULL) {
        return -1;
    }
    //anything positive - null is positive
    else if (a != NULL && b == NULL) {
        return 1;

    }else if (a == NULL && b == NULL) {
        return 0;
    }else {
        PersonPtr *aPerson = (PersonPtr *) a;
        PersonPtr *bPerson  = (PersonPtr *) b;

        return (*aPerson)->age - (*bPerson)->age;
    }
}

//TODO
int compareHeightDescending(const void *a, const void *b) {

    return -1;
}

int main(void) {

    PersonPtr *array = (PersonPtr *) malloc(sizeof(PersonPtr) * ARRAY_SIZE);
    int i;
    
    srand(42);

    for (i = 0; i < ARRAY_SIZE; i++) {
        PersonPtr p = (PersonPtr) malloc(sizeof(Person));
        p->age = rand() % RANGE;
        p->height = rand() % 6;
        array[i] = p;
    }

    printf("Random array is:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("[age: %d, height: %d] ", array[i]->age, array[i]->height);
    }
    printf("\n");

    //sort ascending
    qsort(array, ARRAY_SIZE, sizeof(PersonPtr), compareAgeAscending);

    printf("Sorted ascending by age array is:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("[age: %d, height: %d] ", array[i]->age, array[i]->height);
    }
    printf("\n");

    //TODO: implement the descending comparator and call qsort


    printf("Sorted descending by height array is:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("[age: %d, height: %d] ", array[i]->age, array[i]->height);
    }
    printf("\n");

    for (i = 0; i < ARRAY_SIZE; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}