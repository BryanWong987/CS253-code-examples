#include <stdio.h>


int main(int argc, char **argv) {
    if (argc < 2)
    {
        printf("Usage: %s <argument> [<optional arguments>]\n", argv[0]);
        return -1;
    }

    int i;

    printf("%d arguments passed\n", argc);

    for (i = 0; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

	return 0;

}