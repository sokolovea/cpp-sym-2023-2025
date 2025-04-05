#include "circle.h"
#include "parallelogram.h"
#include "pryamougolnic.h"
#include "rectangle.h"
#include "shape.h"
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool compareShapes(Shape& first, Shape& second) {
    return ((first.getArea() > second.getArea()) && (first.getPerimeter() > second.getPerimeter()));
}

int main()
{
    Circle circle(1);
    Circle* circlePointer = new Circle(1.1);

    Rectangle rectangle(3, 4, 5);
    cout << "Egyptian rectangle P = " << rectangle.getPerimeter() <<
        "; S = " << rectangle.getArea() << endl;
    // Shape shape;

    vector<Shape*> shapes;
    shapes.push_back(&circle);
    shapes.push_back(new Circle(2.5));
    shapes.push_back(new Parallelogram(4, 5, M_PI / 6));
    shapes.push_back(new Parallelogram(4, 5, M_PI_2));
    shapes.push_back(new Pryamougolnic(4, 5));

    cout << "---" << endl;
    for (const auto& eachShape: shapes) {
        cout << "Shape S = " << eachShape->getArea() << "; P = " << eachShape->getPerimeter() << endl;
        cout << "Shape S comparing circlePointer = " << compareShapes(*eachShape, *circlePointer) << endl;
    }
    return 0;
}
