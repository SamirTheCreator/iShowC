#include <stdio.h>

main () {
    float celc, fahr;

    int lower, upper, step;

    lower = -30;
    upper = 100;
    step = 10;

    celc = lower;

    printf("%s\t%s\n", "Celsius", "Fahrenheit");

    while (celc <= upper) {
        fahr = (9.0 / 5.0) * celc - 32.0;
        printf("%7f%8.2f\n", celc, fahr);
        celc = celc + step;
    }
}