#include <cmath>
#include "logic.h"

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

double phi(double x)
{
    return pow(x * x - 5 * x + 10, 0.25);
}

double phi_der(double x)
{
    return (2*x - 5) / (4 * pow((x * x - 5 * x + 10), 2));
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

//Метод пропорциональных частей (хорд)
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

//Метод касательных (Ньютона)
double solve_method_3(double a, double b, double eps)
{
    double x_prev = b;
    double x = a;
    while (fabs(x_prev - x) > eps)
    {
        x_prev = x;
        x = x - f(x) / f_der(x);
    }
    return x;
}

// Модифицированный метод Ньютона
double solve_method_4(double a, double b, double eps)
{
    double x_prev = b;
    double x = a;
    double f_der_x0 = f_der(x);

    double x_prev_prev = b;
    double counter = 0;
    while (pow(x - x_prev, 2) / fabs(2 * x_prev - x - x_prev_prev) > eps && counter < 10000)
    {
        counter++;
        x_prev_prev = x_prev;
        x_prev = x;
        x = x - f(x) / f_der_x0;
    }
    return x;
}


// Комбинированный метод
double solve_method_5(double a, double b, double eps)
{
    double x, y;
    if (f(a) * f_der_der(a) > 0)
    {
        x = a;
        y = b;
    }
    else
    {
        x = b;
        y = a;
    }
    while (fabs(x - y) > eps)
    {
        x = x - f(x) / f_der(x);
        y = y - f(y) * (x - y) / (f(x) - f(y));
    }
    return x;
}


// Метод итераций
double solve_method_6(double a, double b, double eps)
{
    double x = a;
    double x_prev = b;
    while (fabs(x - x_prev) > eps)
    {
        x_prev = x;
        x = phi(x); 
    }
    return x;
}

//Отделение корней
bool define_root(double &a, double &b, double step)
{
    double x_prev = a;
    for (double x = a + step; x < b; x += step)
    {
        if (f(x_prev) * f(x) <= 0 && ((x + x_prev) / 2 > 0))
        {
            a = x_prev;
            b = x;
            return true;
        }
        x_prev = x;
    }
    return false;
}

// int main()
// {
//     printf("%.10lf\n", solve_method_1(1, 2, 0.0001));
//     printf("%.10lf\n", solve_method_2(1, 2, 0.0001));
//     printf("%.10lf\n", solve_method_3(1, 2, 0.0001));
//     printf("%.10lf\n", solve_method_4(1.3, 1.7, 0.0001));
//     printf("%.10lf\n", solve_method_5(1, 2, 0.0001));
//     printf("%.10lf\n", solve_method_6(1, 2, 0.0001));
// }
