#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
	printf("%d = %x\n", 15, 15);
	printf("sin(3) = %.3f\n", sin(3));
    int i = 3;
    float f = 3.0;
    printf("sin(%d) = %.3f\n", i, sin(i));
    printf("sin(%f) = %.3f\n", f, sin(f));
    
    printf("\n---\n");
    printf("p1 = (ln(3 * Pi) + e) / 2\n");
	printf("p2 = p1 * cos(p1 * sin(p1 * cos(p1)))\n");
	printf("y = p1 * x ^ 2 + p2\n");
    printf("Input x:\n");
    double x, p1, p2;
    scanf("%lf", &x);
    p1 = (log(3 * M_PI) + exp(1)) / 2;
    p2 = p1 * cos(p1 * sin(p1 * cos(p1)));
    double y = p1 * pow(x, 2) + p2;
    printf("y(%.2lf) = %.4lf", x, y);
    
    printf("\n---\n");
    const double EPS = 1e-5;
    double a = 1.50005;
    double b = 1.50006;
    printf("%d\n", fabs(a - b) <= EPS);
    b += 0.01;
    printf("%d\n", fabs(a - b) <= EPS);
    printf("%f\n", fabs(-1.4));
    return 0;
}
