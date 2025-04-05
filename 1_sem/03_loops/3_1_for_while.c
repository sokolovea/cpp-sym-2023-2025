#include <stdio.h>
#include <math.h>

const double EPS = 1e-5;
int main()
{
	double x = 0;
	double step = 0.01;
	while (x <= 1 + EPS) //Без погрешности EPS возможны проблемы
	{
		printf("x = %.2lf, sin(x) = %.4lf\n", x, sin(x));
		x += step;
	}
	
	// double x;
	// double x0 = -10;
	// double hx = 3.5;
	// double xn = 10;
	
	// x = x0;
	// while (x <= xn)
	// {
	// 	printf("f(%.1lf) = %.4lf\n", x, pow(x, 4));
	// 	x += hx;	
	// }
	
	// for (double x = x0; x <= xn; x += hx) {
	// 	printf("f(%.1lf) = %.4lf\n", x, pow(x, 4));
	// }
}
