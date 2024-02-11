/*
Exercise 3-4. 
In a two's complement number representation, our version 
of itoa does not handle the largest negative number, that 
is, the value of n equal to -(2wordsize-1). Explain why 
not. Modify it to print that value correctly, regardless
of the machine on which it runs.
*/

/*
Negation in binary is ~n+1;
-2^(wordsize-1) is leftmost bit set;
Negation of this returns back to the same number;

*/

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <assert.h>

void itoa(int n, char s[]);
void reverse(char *str);

int main() {
        char num[100];
        int n = INT_MIN;
        itoa(n, num);

        // assert(n != -n);
        printf("%d\n", n);
        printf("%s\n", num);

        return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]) {
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