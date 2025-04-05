#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "shape.h"

class Parallelogram : public Shape
{
private:
    double a;
    double b;
    double alpha;
public:
    Parallelogram(double a, double b, double aplha);
    double getA() const;
    void setA(double newA);
    double getB() const;
    void setB(double newB);
    double getAlpha() const;
    void setAlpha(double newAplha);

    double getArea() override;
    double getPerimeter() override;
};

#endif // PARALLELOGRAM_H
