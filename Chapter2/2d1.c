/*
Exercise 2-1. 
Write a program to determine the ranges of 
char, short, int, and long variables, both 
signed and unsigned, by printing appropriate 
values from standard headers and by direct 
computation. Harder if you compute them: determine 
the ranges of the various floating-point types.
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main (int argc, char *argv[]) {
/*
        short short_max = SHRT_MAX,
              short_min = SHRT_MIN;
        unsigned short ushort_max = USHRT_MAX;
        int int_max = INT_MAX, 
            int_min = INT_MIN;
        unsigned int uint_max = UINT_MAX;
        char char_max = CHAR_MAX,
             char_min = CHAR_MIN;
        unsigned char uchar_max = UCHAR_MAX;
*/
        printf("Type\t\tMax\t\tMin\n");
        printf("short\t\t%d\t\t%d\n", SHRT_MAX, SHRT_MIN);
        printf("ushort\t\t%d\t\t0\n", USHRT_MAX);
        printf("int\t\t%d\t\t%d\n", INT_MAX, INT_MIN); // 64 bit, interesting...
        printf("uint\t\t%d\t\t%d\n", UINT_MAX, 0);
        printf("char\t\t%d\t\t%d\n", CHAR_MAX, CHAR_MIN);
        printf("uchar\t\t%d\t\t%d\n", UCHAR_MAX, 0);

        // printf("float\t\t%f\t\%f\n", FLT_MAX, FLT_MIN);
        // printf("double\t\t%lf\t\%lf\n", DBL_MAX, DBL_MIN);

        return 0;
}