#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int htoi(char *str);
int chartohex(char c);

int main (void) {
        char hex[] = "0X56AD";
        printf("%d\n", htoi(hex));

        return 0;
}

int htoi(char *str) {
        int i = strlen(str) - 1;
        unsigned int coeff = 1;
        int hexval;
        char c;
        int result = 0;
        
        while ((c = str[i--]) != '\0') {
                if (c == '0' || c == 'x' || c == 'X') {
                        continue;
                }
                hexval = chartohex(c);

                result += hexval * coeff;
                coeff = coeff << 4;
        }

        return result;
}

int chartohex(char c) {
        if (c >= '0' && c <= '9') {
                return c - '0';
        }
        if (c >= 'a' && c <= 'f') {
                return c - 'a' + 10;
        }
        if (c >= 'A' && c <= 'F') {
                return c - 'A' + 10;
        }
        return '\0';
}