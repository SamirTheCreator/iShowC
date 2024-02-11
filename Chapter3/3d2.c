/*
Exercise 3-2.
Write a function escape(s,t) that converts characters 
like newline and tab into visible escape sequences like 
\n and \t as it copies the string t to s. Use a switch. 
Write a function for the other direction as well, 
converting escape sequences into the real characters.
*/

#include <stdio.h>

void escape(char *s, char t);
char epacse(char *s);

int main(void) {
        char newline = '\n';
        char str[3];

        escape(str, newline);
        printf("%s\n", str);

        printf("%c\n", epacse("\\n"));

        return 0;
}

void escape(char *s, char t) {
        s[0] = '\\';
        switch(t) {
                case '\n':
                        s[1] = 'n';
                        break;
                case '\t':
                        s[1] = 't';
                        break;
                default:
                        s[1] = '\0';
                        break;
        }
        s[2] = '\0';
}

char epacse(char *s) {
        if (s[0] != '\\') {
                return '\0';
        }
        switch(s[1]) {
                case 'n': 
                        return '\n';
                case 't':
                        return '\t';
                default:
                        return '\0';
        }
        return '\0';
}