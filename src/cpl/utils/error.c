#include <utils/error.h>
#include <string.h>

void error(const char *func, char *error, unsigned char kill, unsigned char *forget) {
    printf("%s: %s", func, error);
    if (strlen(forget) > 0)
        printf("; did you forget to %s?\n", forget);
    else
        puts(""); //just print newline
    
    if (kill)
        exit(1);
}