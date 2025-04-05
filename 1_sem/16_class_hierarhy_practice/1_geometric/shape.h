#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
    Shape();
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
};

#endif // SHAPE_H
