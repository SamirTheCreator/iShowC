#include <stdio.h>

main () {
    char c;
    int i, j;
    char alph[26];

    for (i = 0; i < 26; ++i) {
        alph[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            alph[c-65]++;
        }
    }
    for (i = 0; i < 26; ++i) {
        printf("%c: ", i+65);
        for (j = 0; j < alph[i]; ++j) {
            printf("#");
        }
        printf("\n");
    }
}