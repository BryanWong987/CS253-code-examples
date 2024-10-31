#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1000

const char* delimiters = " \t@;{}()[].#<>\n\r+-/%*\"^'$~&=!|:\\?,";

int main(int argc, char **argv) {
    if (argc < 3)
    {
        printf("Usage: %s <file-name> <debug>\n", argv[0]);
        return -1;
    }

    char *filename = argv[1];
    int debug = atoi(argv[2]);
    if (debug != 0 && debug != 1) {
        fprintf(stderr, "Error, debug must be 0|1\n");
        return -1;
    }

    char *line, *token;
    int lineSize;
    char c;
    FILE *f = fopen(filename, "r"); //open the file in read mode
    if (f == NULL) {
        perror("fopen");
        exit(1);
    }
    int wordCount = 0;

    while ((c = fgetc(f)) != EOF) //while lines are left
    {
        
        lineSize = 0;
        line = malloc(sizeof(char) * MAX_LINE);

        //read the line in, filling the line buffer up untile MAX_LINE
        while (((c != '\n') && (c != EOF)) && (lineSize < MAX_LINE - 1)) {
            line[lineSize] = c;
            lineSize++;
            c = fgetc(f);
        }
        
        //ensure that the line string is null terminated
        line[lineSize] = '\0';
        //ensure that the line ends with a delimiter from delimiters
        //otherwise, strtok reads beyond the buffer
        line[MAX_LINE - 1] = '\n';

        token = strtok(line, delimiters);
        while (token != NULL) {
            if (debug) printf("%s\n", token);
            wordCount++;
            token = strtok(NULL, delimiters);
        }
        free(line);
    }
    
    printf("number of words is %d\n", wordCount);

    fclose(f); //close otherwise memory leak! 

	return 0;

}