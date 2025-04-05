#include <stdio.h>

int func_1(int parameter) {
	parameter += 10;
	return parameter;
}

void procedure(int parameter) {
	printf("We have %d people!\n", parameter);
	printf("We have %d schools!\n", parameter / 500);
}

float square(float number);

int main() {
	int n = func_1(1000);
	n = func_1(n);
	procedure(1000);
	float a = 12;
	printf("%.2f ** 2 = %.2f", a, square(a));
}

float square(float number) {
	return number * number;
}
