#include <cmath>
#include <iostream>

using namespace std;


class Coordinate {
private:
    // double x, y;
    double phi, r = 0;

public:
    static int printCounter;


    double getPhi() { return this->phi; }
    void setPhi(double phi) {this->phi = phi; }
    double getR() { return this->r; }
    void setR(double r) {this->r = r;}

    double getX() { return this->r * cos(this->phi); }
    double getY() { return this->r * sin(this->phi); }

    //stubs
    void setX() {;}
    void setY() {;}

    void printCoordinates()
    {
        printCounter += 1;
        cout << "X = " << this->getX() << "; Y = " << this->getY() << endl;
        cout << "R = " << this->getR() << "; Phi = " << this->getPhi() << endl;
    }

};

int Coordinate::printCounter = 0;

int main()
{
    Coordinate coordinate = Coordinate();
    coordinate.printCoordinates();
    coordinate.setR(10);
    coordinate.setPhi(3.14159 / 3);
    coordinate.printCoordinates();

    cout << "Coordinates were printed " << Coordinate::printCounter << " times." << endl;

    Coordinate coordinateOther = Coordinate();
    coordinateOther.printCoordinates();
    Coordinate::printCounter = 8347;
    cout << "Coordinates were printed " << Coordinate::printCounter << " times." << endl;
}
