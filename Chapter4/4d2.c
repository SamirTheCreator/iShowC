/*
Extend atof to handle scientific notation of the form
     123.45e-6
  where a floating-point number may be followed by e or E and an optionally signed exponent
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

double atof(char s[]);
void reverse(char *str);

int main(void) {

    printf("%12.0lf", atof("1e11"));

    return 0;
}

double atof(char s[]) {
    double val, power;
    int i, sign, exp_sign, base;
    char *offset;
    power = 1.0;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-') {
            i++;
        }
        base = 1;
        i = strlen(s) - 1;
        while (isdigit(s[i])) {
            for (int j=0; j < (s[i]-'0')*base; j++) 
                power = (exp_sign < 0) ? power * 10 : power / 10;

            base *= 10;
            i--;
        }
    }

    return sign * val / power;
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
