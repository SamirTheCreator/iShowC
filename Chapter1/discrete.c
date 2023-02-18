#include <stdio.h>
#define TRUE 0b1
#define FALSE 0b0


main () {
    /* A program to demostrate Karnaugh Map (K' Map)
       to extent that it is on the lowest level of
       abstraction possible.

       Program operates an 8x3 matrix as on truth table.
       Could have been better with binary and bitwise
       operators. 
       The logic function is F(a,b,c) = a + b~c */

    int i, j, f;
    int a, b, c;

    int tt[8][4] =
        {
            {0, 0, 0, 0},
            {0, 0, 1, 0},
            {0, 1, 0, 1},
            {0, 1, 1, 0},
            {1, 0, 0, 1},
            {1, 0, 1, 1},
            {1, 1, 0, 1},
            {1, 1, 1, 1}
    };

    int kmap[2][4];
    kmap[0][0] = tt[0][3];
    kmap[0][1] = tt[1][3];
    kmap[0][2] = tt[3][3];
    kmap[0][3] = tt[2][3];

    kmap[1][0] = tt[4][3];
    kmap[1][1] = tt[5][3];
    kmap[1][2] = tt[7][3];
    kmap[1][3] = tt[6][3];

    /* Print Karnaugh Map */
    printf("A\\BC\n");
    printf("     00\t\t01\t11\t10\n");


    for (i = 0; i < 2; ++i) {
        printf("%d    %d\t\t%d\t%d\t%d\n",i,  kmap[i][0], kmap[i][1], kmap[i][2], kmap[i][3]);
    }
}
