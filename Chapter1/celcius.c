#include <stdio.h>

main ()
{
	/*
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	while (fahr <= upper) {
		 celsius = 5 * (fahr - 32) / 9;
		 printf("%d\t%d\n", fahr, celsius);
		 fahr = fahr + step;
	}
	*/

	/*
	int num1, num2, num3, num4;

	num1 = 1;
	num2 = 2;
	num3 = 3;
	num4 = 4;

	int count = 10;
	while (count--) {
		num1 = num1 * count;
		num2 = num2 * count;
		num3 = num3 * count;
		num4 = num4 * count;
		
		printf("%d\t%d\t%d\t%d\n", num1, num2, num3, num4);
	}
	*/

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
