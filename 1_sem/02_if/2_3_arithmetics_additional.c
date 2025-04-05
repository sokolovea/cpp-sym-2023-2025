#include <stdio.h>
#include <math.h>

int main() {
	printf("%d\n", 100 / 3);
	printf("%f\n", (float)(100 / 3));
	// printf("%f\n", float(100) / 3); //Форма записи появилась в C++
	printf("%d\n", (int)round((float)100 / 3));
	printf("%d\n", (int)floor((float)100 / 3));
	printf("%d\n", (int)ceil((float)100 / 3));
	
	printf("---\n");
	
	// a = b * q + r, => r = a - b * q
	printf("100 %% 3 = %d\n", 100 % 3); // r = 100 - 33 * 3
	printf("100 / -3 = %d\n", 100 / (-3)); //x86 CPU bug, математически корректно -34
	printf("100 %% -3 = %d\n", 100 % (-3)); //x86 CPU bug, в математике r = 100 - (-34) * (-3) = -2
	
	return 0;
}
