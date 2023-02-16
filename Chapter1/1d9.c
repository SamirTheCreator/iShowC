#include <stdio.h>

main () {
    char c;
    int b = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' && b) {
            continue;
        } else if (c == ' ') {
            b = 1;
        } else {
            b = 0;
        }
        putchar(c);
    }
}