#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void printVector(const vector<int>& vec) {
    for (int elem : vec) {
        cout << elem << " ";
    }
    cout << endl << endl;
}

int main() {
    // 1. �������� ������� � ���������� ����������
    std::vector<int> vec = {1, 5, 2, 4, 3};
    std::cout << "Initial vector: ";
    printVector(vec);

    // 2. ���������� ��������� � ������� push_back
    vec.push_back(6);
    vec.push_back(7);
    std::cout << "After push_back: ";
    printVector(vec);

    // 3. �������� ���������� �������� � ������� pop_back
    vec.pop_back();
    std::cout << "After pop_back: ";
    printVector(vec);

    // 4. ������� �������� � �������� � ������� insert
    vec.insert(vec.begin() + 2, 99);
    std::cout << "After insert at index 2: ";
    printVector(vec);

    // 5. ���������� �������
    std::cout << "After sort: ";
    std::sort(vec.begin(), vec.end());
    printVector(vec);
    std::cout << "After reverse: ";
    std::reverse(vec.begin(), vec.end());
    printVector(vec);

    // 5. �������� �������� �� ������� � ������� erase
    vec.erase(vec.begin() + 1);
    std::cout << "After erase at index 1: ";
    printVector(vec);

    // 6. �������� ���������� ��������� � ������� erase
    vec.erase(vec.begin(), vec.begin() + 2);
    std::cout << "After erasing first two elements: ";
    printVector(vec);

    // 7. ��������� �������� � ������� ��������� []
    std::cout << "Element at index 1: " << vec[1] << "\n";
    std::cout << "Element at index 100: " << vec[100] << "\n"; //dangerous!!!

    try {
        std::cout << "Element at index 100: " << vec.at(100) << "\n";
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    // 8. ��������� ������� � ����������� �������
    std::cout << "Size: " << vec.size() << "\n";
    std::cout << "Capacity: " << vec.capacity() << "\n";

    // 10. ������� ���� ��������� ������� � ������� clear
    vec.clear();
    std::cout << "After clear, size: " << vec.size() << ", capacity: " << vec.capacity() << "\n";

    return 0;
}
