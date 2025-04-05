#include <stdio.h>

int main() {
	int a, b;
	int code = scanf("%d%d", &a, &b);
	if (code == 2)
	{
		printf("No errors!\n");
	}
	else
	{
		printf("Error parsing a, b!\n");
		return 1;
	}
	int length = printf("a = %d, b = %d\n", a, b);
	printf("length = %d\n", length);
	return 0;
}
