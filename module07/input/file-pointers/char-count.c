#include <stdio.h>


int main(void) {

    long nc;
    nc = 0;
    FILE *file = fopen("char-count.c", "r");

    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    while (fgetc(file) != EOF) {
        ++nc;
    }
    printf("%ld\n", nc);


    //fclose(file);

    return 0;
}