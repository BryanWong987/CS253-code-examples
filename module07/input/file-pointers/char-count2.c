#include <stdio.h>


// this version reads from a file input by the user
int main(int argc, char **argv) {

    long nc;
    nc = 0;
    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    while (fgetc(file) != EOF) {
        ++nc;
    }
    printf("%ld\n", nc);


    fclose(file);

    return 0;
}