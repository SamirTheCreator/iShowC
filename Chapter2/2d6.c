/*
Exercise 2-6. 

Write a function setbits(x,p,n,y) that returns 
x with the n bits that begin at position p set 
to the rightmost n bits of y, leaving the other 
bits unchanged.
*/

#include <stdio.h>

unsigned int setbits(int x, int p, int n, int y);

int main(void) {
        printf("%d\n", setbits(5, 4, 4, 11));
        return 0;
}

/*
* Starting with perhaps easiest part is
* to create mask of n rightmost bits of y
*
* ~0 << n is bitmap of ones with 0s in n rightmost bits
*
* ~(~0 << n) is simply the mask to only select n 
* rightmost bits
*
* I move it to the corresponding p location by shifting
* it to the left by p-n+1 bits.
*
* This function assumes user provides sensible args.
*/
unsigned int setbits(int x, int p, int n, int y) {
        return (x & ~((~(~0 << n)) << (p-n+1))) | ((y & ~(~0 << n)) << (p-n+1));
}