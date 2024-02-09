/*
Exercise 2-7. 
Write a function invert(x,p,n) that returns x with the 
n bits that begin at position p inverted (i.e., 1 changed 
into 0 and vice versa), leaving the others unchanged.
*/

#include <stdio.h>

unsigned int invert(int x, int p, int n);

int main(void) {
        printf("%u\n", invert(11, 5, 2));
        return 0;
}

unsigned int invert(int x, int p, int n) {
        return x ^ (~(~0 << n) << (p-n+1));
}