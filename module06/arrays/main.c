#include <stdio.h>

int myStrlen(char src[]) {
    int c = 0;
    int i = 0;
    while (src[i] != '\0') {
        c++;
        i++;
    }

    return c;
}

void myStrcpy(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

}

int main(void) {

    char input[11];
    char output[11];
    input[0] = '\0';
    printf(" %c", input[0]);
    printf("Enter a string\n");
    scanf("%10s", input);

    myStrcpy(output, input);

    printf("output: %s\n", output);
    printf("size of output: %d\n", myStrlen(output));

    return 0;
}




