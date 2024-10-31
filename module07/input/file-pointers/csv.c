#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void) {

    char *csvname = "test.csv";

    /* Open the FILE and validate */
    errno = 0;
    FILE * dataFile = fopen(csvname,"r");
    if (dataFile == NULL) {
        perror("fopen");
        return 1;
    }

    int lineCount = 0;
    int numRead = -1;

    int columnOne;
    int columnTwo;
    char columnThree[80];
    int columnFour;
    while (!feof(dataFile) && !numRead == 0) {
        numRead = fscanf(dataFile,"%d,%d,%79[^,],%d\n",&columnOne,&columnTwo,columnThree,&columnFour);
        if (numRead == 4) {
            printf("read CSV line:\n\t%d\n\t%d\n\t%s\n\t%d\n",
                                                                columnOne,
                                                                columnTwo,
                                                                columnThree,
                                                                columnFour);
            lineCount++;

        } else {
            fprintf(stderr,"Error:  Only read %d of 4\n", numRead);
        }
    }

    fclose(dataFile);

    fprintf(stdout,"Read %d rows\n", lineCount);

    return 0;
}