/*
Exercise 4-1. 
Write the function strindex(s,t) which returns the 
position of the rightmost occurrence of t in s, or 
-1 if there is none.
*/

#include <stdio.h>
#include <string.h>

int strindex(char *s, char *t);
void reverse(char *s);

int main(void) {
        char str[] = "samsamsamsam";
        char pattern[] = "sam";

        printf("%d\n", strindex(str, pattern));
        return 0;
}

int strindex(char *s, char *t) {
        int len_s = strlen(s);
        int len_t = strlen(t);
        reverse(s);
        reverse(t);

        int i, j, k;
        for (i = 0; s[i] != '\0'; i++) {
                for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
                        ;
                if (k > 0 && t[k] == '\0')
                        return (len_s - len_t) - i;
        }
        return -1;
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