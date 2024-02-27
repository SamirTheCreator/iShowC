#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define NUMBER '0' /* signal that a number was found */

int getch(void);
void ungetch(int);
bool negative;

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-' && c != '>')
        return c; /* not a number */
    i = 0;
    if (c == '>') {
        while(islower(c = getch())) 
            s[i++] = c;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        return '>';
    }
    if (c == '-' || isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (!strcmp(s, "-"))
        return '-';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}