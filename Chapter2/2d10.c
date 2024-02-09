/*
Exercise 2-10. 
Rewrite the function lower, which converts upper 
case letters to lower case, with a conditional 
expression instead of if-else.
*/

#include <stdio.h>

void lower(char *str);

int main(void) {
        char name[] = "SAMIR ISma name";

        lower(name);

        printf("%s\n", name);

        return 0;
}

void lower(char *str) {
        int i = 0;
        while (str[i] != '\0') {
                str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] = str[i] - 'A' + 'a' : str[i];
                i++;
        }
}