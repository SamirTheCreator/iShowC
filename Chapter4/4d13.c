/*
“Exercise 4-12. Adapt the ideas of printd to write 
a recursive version of itoa; that is, convert an 
integer into a string by calling a recursive routine.”
*/

#include <stdio.h>
#include <string.h>

#define abs(i) (i < 0 ? -i : i)

void itoa(int n, char s[]);
void reverse(char *str, int i);

int main(void) {
    char number[64];
    int num = 1000000;

    itoa(num, number);
    printf("%s\n", number);

    return 0;
}

void itoa(int n, char s[]) {
    static int i;

    if (n / 10)
        itoa(n / 10, s);
    else {
        i = 0;
        if (n < 0)
            s[i++] = '-';
    }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}

void reverse(char *str, int i) {
    if (i > strlen(str) / 2) {
        return;
    }
    char c = str[i];
    str[i] = str[strlen(str)-1 - i];
    str[strlen(str)-1 - i] = c;

    reverse(str, i+1);
}
