#define _GNU_SOURCE //this is the feature_test_macro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printUsage(const char *programName) {
    fprintf(stdout,"Usage: %s [-d <arg>] [-a] [-f]\n", programName);
    fprintf(stdout,"\t-d <arg>  print whatever arg is\n");
    fprintf(stdout,"\t-a        print option a\n");
    fprintf(stdout,"\t-f        print option f\n");
    fprintf(stdout,"\t-h        print this help\n");
}

int main(int argc, char **argv) {

    int opt;

    while ( (opt = getopt(argc, argv, "d:afh")) != -1 ) {
        switch (opt) {
            case 'd':
                printf("optarg is %s\n", optarg);
                break;
            case 'a':
                printf("option a selected\n");
                break;
            case 'f':
                printf("option f selected\n");
                break;
            case 'h':
                printUsage(argv[0]);
                exit(0);
            default:
                printUsage(argv[0]);
                exit(1);
        }
    }
}