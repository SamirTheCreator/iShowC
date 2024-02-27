#include <stdio.h>
#define BUFSIZE 100

char buf = EOF; /* buffer for ungetch */

int getch(void) /* get a (possibly pushed-back) character */
{
    return (buf == EOF) ? buf : getchar();
}
void ungetch(int c) /* push character back on input */
{
    buf = c;
}