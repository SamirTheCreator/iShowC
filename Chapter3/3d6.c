/*
Exercise 3-6.
Write a version of itoa that accepts three arguments 
instead of two. The third argument is a minimum field 
width; the converted number must be padded with blanks 
on the left if necessary to make it wide enough.
*/

#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int min_width);
void reverse(char *str);

int main(void) {
        char num[100];
        int n = 99939;
        itoa(n, num, 4);

        // assert(n != -n);
        printf("%d\n", n);
        printf("%s\n", num);

        return 0;
}

void itoa(int n, char s[], int min_width) {
        unsigned int of;
        int i, sign;
        if ((sign = n) < 0) /* record sign */
                n = -n; /* make n positive */
        i = 0;
        if (n == -n) {
                of = n;
                do { /* generate digits in reverse order */
                        s[i++] = of % 10 + '0'; /* get next digit */
                } while ((of /= 10) > 0); /* delete it */
        } else {
                do { /* generate digits in reverse order */
                        s[i++] = n % 10 + '0'; /* get next digit */
                } while ((n /= 10) > 0); /* delete it */
        }
        if (sign < 0)
                s[i++] = '-';
        if (i < min_width) {
                for (; i < min_width; i++) {
                        s[i] = ' ';
                }
        }
        s[i] = '\0';
        reverse(s);
}

void reverse(char *str) {
        char c;
        int len = strlen(str) - 1;
        for (int i = 0; i <= len/2; i++) {
                c = str[i];
                str[i] = str[len - i];
                str[len - i] = c;
        }
}