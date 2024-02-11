/*
Exercise 3-3.
Write a function expand(s1,s2) that expands shorthand 
notations like a-z in the string s1 into the equivalent 
complete list abc...xyz in s2. Allow for letters of 
either case and digits, and be prepared to handle cases 
like a-b-c and a-z0-9 and -a-z. Arrange that a leading 
or trailing - is taken literally.
*/

#include <stdio.h>
#include <assert.h>

void expand(char s1[], char s2[]);

int main(void) {
        char s1[] = "-a-b-c-d-e-z0-9";
        char s2[1000];

        expand(s1, s2);
        printf("%s\n", s2);

        return 0;
}

void expand(char s1[], char s2[]) {
        int i = 0;
        int j = 0;
        char from, to;
        char c;

        for (; s1[i] == '-'; i++);

        while ((c = s1[i++]) != '\0') {
                if (c == '-') {
                        from = s1[i-2];
                        to = s1[i];

                        assert(
                                (from >= 'A' && to <= 'Z') || 
                                (from >= 'a' && to <= 'z') || 
                                (from >= '0' && to <= '9')
                        );
                        assert(from <= to);

                        from += 1; // we have already copied it in previous iteration
                        for (char c = from; c < to; c++) {
                                s2[j++] = c;
                        }
                } else {
                        s2[j++] = c;
                }
        }
}