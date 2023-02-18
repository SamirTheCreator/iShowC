#include <stdio.h>
#define IN 1
#define OUT 0

main () {

    // A program that prints its input one word per line

    char c;

    int state = IN;

    while ((c = getchar()) != EOF) {
        putchar(c);
        if (c == ' ') {
            printf("\n");
        }
    }
}