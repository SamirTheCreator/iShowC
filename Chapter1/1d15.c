#include <stdio.h>

float fahr_to_celc(float fahr) {
	return (5.0/9.0) * (fahr - 32.0);
}

int main(void)
{
	float fahr, celcius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while (fahr <= upper) {
		celcius = fahr_to_celc(fahr);
		printf("%3.0f\t%6.1f\n", fahr, celcius);
		fahr += step;
	}
}

