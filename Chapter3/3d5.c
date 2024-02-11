/*
Exercise 3-5. 
Write the function itob(n,s,b) that converts 
the integer n into a base b character representation 
in the string s. In particular, itob(n,s,16) formats 
s as a hexadecimal integer in s.
*/

#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char *str);

int main() {
        char str[100];
        
        itob(249, str, 16);
        printf("%s\n", str);

        return 0;
}

void itob(int n, char s[], int b) {
        int i, sign;
        if ((sign = n) < 0)
                n = -n;
        i = 0;
        do {
                s[i++] = n%b + ((n%b >= 0 && n%b <= 9) ? '0' : (-10 + 'A')); /* get next digit */
        } while ((n /= b) > 0);
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
