#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(void) {

    char *line;
    char *prompt = "CS253 $>";
    using_history(); /* enable readline history mechanism */
    while ((line = readline(prompt))) {
        printf("%s\n", line);
        add_history(line); /* add current line to history list */
        free(line);
    }
    exit(0);
}