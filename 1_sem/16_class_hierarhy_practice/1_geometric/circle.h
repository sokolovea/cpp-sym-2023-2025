#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

class Circle : public Shape
{
private:
    double r;
public:
    Circle(double r);
    double getR() const;
    void setR(double newR);
    double getArea() override;
    double getPerimeter() override;
};

#endif // CIRCLE_H
