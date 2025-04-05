#include "circle.h"
#include <cmath>

Circle::Circle(double r)
{
    this->r = r;
}

double Circle::getR() const
{
    return r;
}

void Circle::setR(double newR)
{
    r = newR;
}

double Circle::getArea()
{
    return M_PI * r * r;
}

double Circle::getPerimeter()
{
    return 2 * M_PI * r;
}
