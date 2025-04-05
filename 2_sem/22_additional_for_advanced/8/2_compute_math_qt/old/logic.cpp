#include <cmath>
#include <iostream>
#include <cstdio>

using namespace std;

double f(double x)
{
    return x * x * x * x - x * x + 5 * x - 10;
}

double f_der(double x)
{
    return 4 * x * x * x - 2 * x + 5;
}

double f_der_der(double x)
{
    return 12 * x * x - 2;
}

double solve_method_1(double a, double b, double eps)
{
    double c = (a + b) / 2;
    if (fabs(a - b) <= eps)
    {
        return c;
    }
    if (f(a) * f(c) > 0)
    {
        return solve_method_1(c, b, eps);
    }
    return solve_method_1(a, c, eps);
}


double solve_method_2(double a, double b, double eps)
{
    double x_prev = b;
    double x = a;
    while (fabs(x_prev - x) > eps)
    {
        x_prev = x;
        x = x - f(x) * (b - x) / (f(b) - f(x));
    }
    return x;
}

double solve_method_3(double a, double b, double eps)
{
    double x_prev = b;
    double x = a;
    int counter = 0;
    while (fabs(x_prev - x) > eps)
    {
        cout << ++counter << endl;
        x_prev = x;
        x = x - f(x) / f_der(x);
    }
    return x;
}

double solve_method_4(double a, double b, double eps)
{
    double x_prev = b;
    double x = a;
    double f_der_x0 = f_der(x);
    //pow(x - x_prev, 2) / fabs(2 * x_prev - x - x_prev_prev) > eps
    //fabs(x_prev - x) > eps
    //fabs(x_prev - x) > pow(x - x_prev, 2) * f_der_der(b) / f_der(a)
    int counter = 0;
    double x_prev_prev = b;
    while (pow(x - x_prev, 2) / fabs(2 * x_prev - x - x_prev_prev) > eps)
    {
        cout << ++counter << endl;
        x_prev_prev = x_prev;
        x_prev = x;
        x = x - f(x) / f_der_x0;
    }
    return x;
}

int main()
{
    printf("%.10lf\n", solve_method_1(-3, 2, 0.0001));
    printf("%.10lf\n", solve_method_2(-3, -2, 0.0001));
    printf("%.10lf\n", solve_method_3(-3, -2, 0.0001));
    printf("%.10lf\n", solve_method_4(-35, -2, 0.0001));
}