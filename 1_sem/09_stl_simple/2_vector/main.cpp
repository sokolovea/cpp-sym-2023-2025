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
    // 1. Создание вектора с начальными элементами
    std::vector<int> vec = {1, 5, 2, 4, 3};
    std::cout << "Initial vector: ";
    printVector(vec);

    // 2. Добавление элементов с помощью push_back
    vec.push_back(6);
    vec.push_back(7);
    std::cout << "After push_back: ";
    printVector(vec);

    // 3. Удаление последнего элемента с помощью pop_back
    vec.pop_back();
    std::cout << "After pop_back: ";
    printVector(vec);

    // 4. Вставка элемента в середину с помощью insert
    vec.insert(vec.begin() + 2, 99);
    std::cout << "After insert at index 2: ";
    printVector(vec);

    // 5. Сортировка вектора
    std::cout << "After sort: ";
    std::sort(vec.begin(), vec.end());
    printVector(vec);
    std::cout << "After reverse: ";
    std::reverse(vec.begin(), vec.end());
    printVector(vec);

    // 5. Удаление элемента по индексу с помощью erase
    vec.erase(vec.begin() + 1);
    std::cout << "After erase at index 1: ";
    printVector(vec);

    // 6. Удаление нескольких элементов с помощью erase
    vec.erase(vec.begin(), vec.begin() + 2);
    std::cout << "After erasing first two elements: ";
    printVector(vec);

    // 7. Получение элемента с помощью оператора []
    std::cout << "Element at index 1: " << vec[1] << "\n";
    std::cout << "Element at index 100: " << vec[100] << "\n"; //dangerous!!!

    try {
        std::cout << "Element at index 100: " << vec.at(100) << "\n";
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }

    // 8. Получение размера и вместимости вектора
    std::cout << "Size: " << vec.size() << "\n";
    std::cout << "Capacity: " << vec.capacity() << "\n";

    // 10. Очистка всех элементов вектора с помощью clear
    vec.clear();
    std::cout << "After clear, size: " << vec.size() << ", capacity: " << vec.capacity() << "\n";

    return 0;
}
