#include <stdio.h>
#include <time.h>

long factorial(int n) {
	if (n <= 1) {
		return 1;
	}
	return n * factorial(n - 1);
}

long fibonacci(int n) {
	if (n <= 1) {
		return n;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}


long resultArray[200] = {0, 1};
long fibonacciPlus(int n) {
	if (n <= 1) {
		return n;
	}
	if (resultArray[n] != 0) {
		return resultArray[n];
	}
	resultArray[n] = fibonacciPlus(n - 1) + fibonacciPlus(n - 2);
	return resultArray[n];
}

long factorialMod(int n) {
	if (n <= 1) {
		return 1;
	}
	return n * factorial(n - 1) % 100;
}

void test(long (*funcPtr)(int), int parameter) {
   	clock_t begin = clock();
	long longResult = funcPtr(parameter);
	clock_t end = clock();
	printf("funcPtr(%d) = %ld; time = %.3lf sec.\n", parameter, longResult, (double)(end - begin) / CLOCKS_PER_SEC);
}

int main() {
	test(fibonacci, 43);
	test(fibonacciPlus, 43);
	long longResult;
	clock_t begin;
	clock_t end;
	printf("factorial(5) = %ld\n", factorial(5));
	printf("fibonacci(6) = %ld\n", fibonacci(6));
	
	begin = clock();
	longResult = fibonacci(43);
	end = clock();
	printf("fibonacci(43) = %ld; time = %.3lf sec.\n", longResult, (double)(end - begin) / CLOCKS_PER_SEC);


	begin = clock();
	longResult = fibonacciPlus(43);
	end = clock();
	printf("fibonacciPlus(43) = %ld; time = %.3lf sec.\n", longResult, (double)(end - begin) / CLOCKS_PER_SEC);
	
	longResult = 1;
	
	begin = clock();
	for (long i = 1; i <= 40000; i++) {
		longResult *= i;
		longResult %= 100;
	}
	end = clock();
	
	printf("iteration: time = %.3lf sec.\n", (double)(end - begin) / CLOCKS_PER_SEC);
	
	begin = clock();
	longResult = factorialMod(40000);
	end = clock();
	
	printf("recursion: time = %.3lf sec.\n", (double)(end - begin) / CLOCKS_PER_SEC);
}
