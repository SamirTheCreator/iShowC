#include <stdio.h>
#define IN 1
#define OUT 0


main () {
    char c;

    int hist[15];
    int state, len, i;

    for (i = 0; i < 15; ++i) {
        hist[i] = 0;
    }

    len = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            hist[len]++;
            len = 0;
        } else {
            len++;
        }
    }
    
    printf("%s\t%s\n", "Length", "Freq");
    for (i = 1; i < 14; ++i) {
        printf("%d ", i);
        for (int j = 0; j < hist[i]; ++j) {
            printf("#");
        }
        printf("\n");
    }
}