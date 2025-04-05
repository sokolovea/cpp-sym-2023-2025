#include <iostream>
#include "my_vector.h"

void printVectorInfo(MyVector& myVector) {
    std::cout << "\nSize: " << get_size(myVector) << std::endl;
    std::cout << "Capacity: " << myVector.capacity << std::endl;
}

int main() {
    MyVector myVector;
    init(myVector);
    printVectorInfo(myVector);

    push_back(myVector, 1);
    push_back(myVector, 2);
    printVectorInfo(myVector);

    push_back(myVector, 3);
    printVectorInfo(myVector);

    push_back(myVector, 4);
    push_back(myVector, 5);
    printVectorInfo(myVector);
    std::cout << std::endl;

    std::cout << "Elements: ";
    bool isError;
    for (int i = 0; i < get_size(myVector); i++) {
        std::cout << get_element(myVector, i, isError) << " ";
    }

    pop_back(myVector);
    std::cout << std::endl << "After pop_back, size: " << std::endl;
    printVectorInfo(myVector);

    destroy(myVector);
    return 0;
}
