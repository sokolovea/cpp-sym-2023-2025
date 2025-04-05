#include "parallelogram.h"
#include <cmath>

Parallelogram::Parallelogram(double a, double b, double aplha) : a(a),
    b(b),
    alpha(aplha)
{}

double Parallelogram::getA() const
{
    return a;
}

void Parallelogram::setA(double newA)
{
    a = newA;
}

double Parallelogram::getB() const
{
    return b;
}

void Parallelogram::setB(double newB)
{
    b = newB;
}

double Parallelogram::getAlpha() const
{
    return alpha;
}

void Parallelogram::setAlpha(double newAplha)
{
    alpha = newAplha;
}

double Parallelogram::getArea()
{
    return a * b * sin(alpha);
}

double Parallelogram::getPerimeter()
{
    return 2 * (a + b);
}

