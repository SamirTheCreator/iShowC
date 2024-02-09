/*
Exercise 2-8. 
Write a function rightrot(x,n) that returns the value 
of the integer x rotated to the right by n positions.
*/

#include <stdio.h>

#define BYTE_SIZE_BITS 8

unsigned int rightrot(unsigned int x, unsigned int n);

int main(void) {
        printf("%d\n", rightrot(64, 6)); // 1 expected
        printf("%d\n", rightrot(32, 5)); // 1 expected
        printf("%d\n", rightrot(16, 4)); // 1 expected
        printf("%d\n", rightrot(8, 3)); // 1 expected
        printf("%d\n", rightrot(4, 2)); // 1 expected
        printf("%d\n", rightrot(2, 1)); // 1 expected
        printf("%d\n", rightrot(1, 0)); // 1 expected
        
        return 0;
}

unsigned int rightrot(unsigned int x, unsigned int n) {
        int bit;
        for (int i=0; i < n; i++) {
                bit = x & 1;
                x = x >> 1;
                if (bit) {
                        x |= 1 << (sizeof(x)*BYTE_SIZE_BITS - 1);
                } else {
                        x &= ~(1 << (sizeof(x)*BYTE_SIZE_BITS - 1));
                }
        }
        return x;
}