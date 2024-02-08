/*
Exercise 2-4. 
Write an alternative version of squeeze(s1,s2) 
that deletes each character in s1 that matches 
any character in the string s2.
*/

#include <stdio.h>
#include <stdbool.h>

void squeeze(char *s1, char *s2);
bool belongs(char c, char *s);

int main (void) {
        char s1[] = "miraziz";
        char s2[] = "azizchik";

        squeeze(s1, s2);
        printf("%s\n", s1);
        
        return 0;
}

void squeeze(char *s1, char *s2) {
        int i = 0;
        int j = 0;
        char c;

        while ((c = s1[i++]) != '\0') {
                if (!belongs(c, s2)) {
                        s1[j++] = c;
                }
        }
        s1[j] = '\0';
}

bool belongs(char c, char *s) {
        int i = 0;
        char d;

        while ((d = s[i++]) != '\0') {
                if (c == d) {
                        return true;
                }
        }
        return false;
}