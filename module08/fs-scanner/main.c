/* Adapted from GNU manual 
 * https://www.gnu.org/software/libc/manual/html_node/Simple-Directory-Lister-Mark-II.html
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <dirent.h>

#define UNUSED(x) (void)x

static int one (const struct dirent *unused) {
    UNUSED(unused);
    return 1;
}

int main (void) {
    struct dirent **eps;
    int n;

    n = scandir("./", &eps, one, alphasort);
    if (n >= 0) {
        int cnt;
        for (cnt = 0; cnt < n; ++cnt)
        fprintf(stdout, "%s\n", eps[cnt]->d_name);
    } else {
        perror ("Couldn't open the directory");
    }

    return 0;
}