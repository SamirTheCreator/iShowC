#include <stdio.h>

main () {
    float fahr, celsius;
	int step, lower, upper;

	step = 20;
	lower = 0;
	upper = 300;

	fahr = lower;

	printf("%s\t%s\n", "Celsius", "Fahrenheit");

	while (fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%7.0f\t%10.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}