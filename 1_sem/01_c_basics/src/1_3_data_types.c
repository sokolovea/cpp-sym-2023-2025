#include <stdio.h>

#define PI 3.14159265358979323846

int main()
{
    int i = 100;
    printf("i = %d\n", i);
    
    i = 100.99;
    printf("i = %d\n", i);
    
    i = i + 1;
    printf("i = %d\n", i);
    
    int j = -100.99;
    printf("j = %d\n", j);
    
    float f = PI;
    double g = PI;
	printf("Pi = 3.14159265358979323846\n");
    printf(" f = %.20f\n g = %.20lf\n", f, g);
    
    f = 1e+6 + 1;
	printf("%d\n", f == 1e+6);
	// int b = f == 1e+6; //bool since c++
	// printf("%d\n", b);

	f = 1e+6 + 0.01;
	printf("%d\n", f == 1e+6);
    return 0;
}
