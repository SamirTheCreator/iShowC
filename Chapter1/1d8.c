#include <stdio.h>

main () {
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
}