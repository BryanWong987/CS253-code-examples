#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>  // for opendir(), readdir(), closedir()
#include <errno.h>   // for errno
#include <string.h>  // for strerror()

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // Open the directory
    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

    struct dirent *entry;

    // Read entries from the directory
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Check for read errors
    if (errno != 0) {
        perror("Error reading directory");
        closedir(dir);
        return 1;
    }

    // Close the directory
    if (closedir(dir) == -1) {
        perror("Error closing directory");
        return 1;
    }

    return 0;
}
