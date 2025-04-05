#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape
{
private:
    double a;
    double b;
    double c;
public:
    Rectangle(double a, double b, double c);
    double getA() const;
    void setA(double newA);
    double getB() const;
    void setB(double newB);
    double getC() const;
    void setC(double newC);
    double getArea() override;
    double getPerimeter() override;
};

#endif // RECTANGLE_H
