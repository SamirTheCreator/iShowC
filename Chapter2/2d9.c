/*
Exercise 2-9. 
In a two's complement number system, x &= (x-1) deletes 
the rightmost 1-bit in x. Explain why. Use this observation 
to write a faster version of bitcount.
*/

/*
* x-1 in binary representation is basically the same bitset,
* but but at position of rightmost 1-bit in ex-x (pun intended)
* the bit is 0, thus 'and'ing these two bits will always result
* in it being 0.
*/

#include <stdio.h>

int main(void) {
        int x = 37;
        int popcount = 0;

        if (x != 0) popcount++;

        while (x &= (x-1)) {
                popcount += 1;
        }

        printf("%d\n", popcount);
        return 0;
}