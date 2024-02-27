#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include <string.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */


int getop(char []);
void push(double);
double pop(void);
void handlemath(char s[]);
extern int sp;

/* reverse Polish calculator */
int main(void)
{
    int type;
    double op2, op3;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0) {
                    push(fmod(pop(), op2));
                } else {
                    printf("error: modulo zero");
                }
                break;
            case '^':   /* command to peek */
                op2 = pop();
                printf("\t%.8g\n", pop());
                push(op2);
                break;
            case 'x':
                sp = 0;
                break;
            case 's':
                op2 = pop();
                op3 = pop();
                push(op3);
                push(op2);
                break;
            case 'd':
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case '>': /* math functions, example: >sin*/
                handlemath(s);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

void handlemath(char s[]) {
    if (!strcmp(s, "sin")) {
        push(sin(pop()));
    } else if (!strcmp(s, "exp")) {
        push(exp(pop()));
    } else if (!strcmp(s, "pow")) {
        double op2 = pop();
        push(pow(pop(), op2));
    } else {
        printf("math.error: unknown command");
    }
}