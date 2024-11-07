#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE 256

int GetNumOfNonWSCharacters(const char usrStr[]) {
    int count;
    unsigned i;

    count = 0;

    for (i = 0; i < strlen(usrStr); ++i) {
        if (usrStr[i] != ' ' && usrStr[i] != '\t' && usrStr[i] != '\0'
            && usrStr[i] != '\n') {
            ++count;
        }
    }

    return count;
}

int GetNumOfWords(const char usrStr[]) {
    int count;
    unsigned i;

    count = 0;

    for (i = 1; i < strlen(usrStr); ++i) {
        if (isspace(usrStr[i]) && !isspace(usrStr[i - 1])) {
            ++count;
        }
    }

    if (!isspace(usrStr[strlen(usrStr) - 1])) {
        ++count;
    }

    return count;
}

void ShortenSpace(char usrStr[]) {
    unsigned i;
    char tmp[256] = "";
    int length;


    for (i = 1; i < strlen(usrStr); ++i) {
        if (!(isspace(usrStr[i]) && isspace(usrStr[i - 1]))) {
            length = strlen(tmp);
            tmp[length] = usrStr[i - 1];
            tmp[length + 1] = '\0';
        }

        if (i == strlen(usrStr) - 1) {
            length = strlen(tmp);
            tmp[length] = usrStr[i];
            tmp[length + 1] = '\0';
        }
    }

    strcpy(usrStr,tmp);
}



// get words, get nonWS chars, shorten spaces, and fix capitals
void printUsage(const char *programName) {
    fprintf(stdout,"Usage: %s [-w] [-c] [-s] [-f <filename>] [-h]\n", programName);
    fprintf(stdout,"\t-w            print number of words\n");
    fprintf(stdout,"\t-c            print number of non-whitespace characters\n");
    fprintf(stdout,"\t-s            shorten spaces\n");
    fprintf(stdout,"\t-f <filename> REQUIRED: Filename to read text from\n");
    fprintf(stdout,"\t-h            print this help\n");
}

int main(int argc, char **argv) {

    int opt;
    bool countWords = false;
    bool countCharacters = false;
    bool shortenSpaces = false;
    bool providedFile = false;
    char *filename;
    int wordCount = 0;
    int charCount = 0;

    char *line;
    int lineSize;
    char c;

    while ( (opt = getopt(argc, argv, "wcsf:h")) != -1 ) {
        switch (opt) {
            case 'w':
                countWords = true;
                break;
            case 'c':
                countCharacters = true;
                break;
            case 's':
                shortenSpaces = true;
                break;
            case 'f':
                filename = optarg;
                providedFile = true;
                break;
            case 'h':
                printUsage(argv[0]);
                exit(0);
            default:
                printUsage(argv[0]);
                exit(1);
        }
    }

    if (providedFile == false) {
        fprintf(stderr, "Filename is required\n");
        printUsage(argv[0]);
        exit(-1);
    }

    FILE *f = fopen(filename, "r"); //open the file in read mode
    if (f == NULL) {
        perror("fopen");
        exit(1);
    }

    //while there are lines
    while ((c = fgetc(f)) != EOF) {
        
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

        if (countWords == true) {
            wordCount += GetNumOfWords(line);
        }

        if (countCharacters == true) {
            charCount += GetNumOfNonWSCharacters(line);
        }

        if (shortenSpaces == true) {
            ShortenSpace(line);
        }

        printf("%s\n", line);

        free(line);
    }

    if (countWords == true) {
        printf("Non WS Word Count: %d\n", wordCount);
    }

    if (countCharacters == true) {
        printf("Non Character Count: %d\n", charCount);
    }

    fclose(f);
}