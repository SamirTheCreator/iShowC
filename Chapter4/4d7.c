/*
Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input.
Should ungets know about buf and bufp, or should it just use ungetch?
*/

#include <stdio.h>
#include <string.h>

#define MAXSTR 200

extern int bufp;
void ungets(char *s);
int my_getline(char *line, int maxLength);
int getch(void);
void ungetch(int c);

int main(void) {
    char s[MAXSTR];
    my_getline(s, MAXSTR);

    ungets(s);

    while (bufp > 0) {
        putchar(getch());
    }
    putchar('\n');

    return 0;
}

void ungets(char *s) {
    char c;
    int i = strlen(s);
    while (i >= 0) {
        ungetch(s[--i]);
    }
}

int my_getline(char *line, int maxLength) {      
      char ch;
      int length = 0;
      while ((ch = getchar()) != EOF && ch != '\n' && length < maxLength) {
          line[length] = ch;
          length++;
      }
      if (ch == '\n') {
          line[length] = '\0';
      }
      return length;
}