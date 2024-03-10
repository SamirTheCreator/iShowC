/*
“Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t. (Block structure will help.)”
*/

#include <stdio.h>
#define swap(t, x, y) t tmp = x; x = y; y = tmp

int main() {
    int a = 5;
    int b = 6;
    printf("a\tb\n%d\t%d\n", a, b);
    swap(int, a, b);
    printf("%d\t%d\n", a, b);

    return 0;
}