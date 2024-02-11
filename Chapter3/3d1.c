/*
* Exercise 3-1.
* Our binary search makes two tests inside the loop, when one
* would suffice (at the price of more tests outside.) Write a 
* version with only one test inside the loop and measure the 
* difference in run-time.
*/

/*
mybinsearch
./a.out  0.00s user 0.00s system 0% cpu 0.458 total
./a.out  0.00s user 0.00s system 70% cpu 0.005 total

binsearch
./a.out  0.00s user 0.00s system 0% cpu 0.444 total
./a.out  0.00s user 0.00s system 67% cpu 0.003 total
*/

#include <stdio.h>

int mybinsearch(int x, int v[], int n);
int binsearch(int x, int v[], int n);

int main(void) {
        // Tests
        int arr[] = {
                -98, -96, -94, -93, -90, -89, -86, -86, -85, -83,
                -81, -75, -73, -73, -71, -69, -64, -63, -62, -62,
                -61, -61, -56, -54, -53, -50, -49, -47, -46, -43,
                -43, -43, -39, -38, -37, -34, -33, -32, -25, -25,
                -24, -21, -20, -16, -15, -14, -11, -10,  -9,  -5,
                -5,  -1,  +1,  +1,  +2,  +3,  +4, +16, +16, +18,
                +19, +19, +21, +21, +22, +23, +23, +24, +25, +25,
                +29, +30, +32, +33, +34, +35, +36, +37, +41, +52,
                +55, +57, +57, +57, +58, +59, +60, +61, +68, +68,
                +69, +70, +70, +75, +83, +83, +83, +91, +96, +97,
        };

        printf("%d\n", binsearch(97, arr, sizeof(arr)/sizeof(arr[0])));

        return 0;
}

int mybinsearch(int x, int v[], int n)
{
        int low, high, mid;
        low = 0;
        high = n - 1;
        while (low <= high) {
                mid = (low+high)/2;
                if (x < v[mid])
                        high = mid - 1;
                else
                        low = mid + 1;
        }
        if (low <= high || v[mid] == x)
                return mid;
        return -1; /* no match */
}

int binsearch(int x, int v[], int n)
{
        int low, high, mid;
        low = 0;
        high = n - 1;
        while (low <= high) {
                mid = (low+high)/2;
                if (x < v[mid])
                        high = mid - 1;
                else if (x > v[mid])
                        low = mid + 1;
                else /* found match */
                        return mid;
        }
        return -1; /* no match */
}
