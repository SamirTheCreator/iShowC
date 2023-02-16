#include <stdio.h>

main () {
    /* char c;

    c = getchar();

    putchar(c);

    putchar(10); */

   /*  int res = getchar()!=EOF;

    printf("%s\t%d\n", "getchar()!=EOF is ", res);

    printf("%s\t%d\n", "EOF = ", EOF);

    int c;

    while ((c=getchar()) != EOF) {
        putchar(c);
    }

     */
/* 
    long nc;
    char c;

    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc); */

    /* // Program to calculate number of blanks, tabs and newlines;

    int blnks=0, tbs=0, nls=0;

    char c;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++blnks;
        else if (c == '\t')
            ++ tbs;
        else if (c == '\n') 
            ++ nls;
    }

    printf("%s\t%s\t%s\n", "Blanks", "Tabs", "New Lines");
    printf("%6d\t%4d\t%9d\n", blnks, tbs, nls);
 */

    /* char c;
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
    } */
    
}
