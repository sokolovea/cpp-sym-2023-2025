#include "rectangle.h"
#include <cmath>

Rectangle::Rectangle(double a, double b, double c) : a(a),
    b(b),
    c(c)
{}

double Rectangle::getA() const
{
    return a;
}

void Rectangle::setA(double newA)
{
    a = newA;
}

double Rectangle::getB() const
{
    return b;
}

void Rectangle::setB(double newB)
{
    b = newB;
}

double Rectangle::getC() const
{
    return c;
}

void Rectangle::setC(double newC)
{
    c = newC;
}

double Rectangle::getArea()
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Rectangle::getPerimeter()
{
    return a + b + c;
}
