/*
Exercise 2-5.
Write the function any(s1,s2), which returns the first 
location in a string s1 where any character from the 
string s2 occurs, or -1 if s1 contains no characters 
from s2. (The standard library function strpbrk does 
the same job but returns a pointer to the location.)
*/

#include <stdio.h>
#include <stdbool.h>

int any(char *s1, char *s2);
bool belongs(char c, char *s);

int main(void) {
        char s1[] = "samir";
        char s2[] = "amir";

        printf("%d\n", any(s1, s2));

        return 0;
}

int any(char *s1, char *s2) {
        int i = 0;
        char c;
        while ((c = s1[i++]) != '\0') {
                if (belongs(c, s2)) {
                        return i;
                }
        }
        return -1;
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