#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    set<int> numbers = {5, 3, 8, 1, 4};

    numbers.insert(10); //вставка элементов
    numbers.insert(2);
    numbers.insert(2);
    numbers.insert(2);
    numbers.insert(2);
    numbers.insert(2);

    numbers.erase(3); //удаление элементов

    if (numbers.find(8) != numbers.end()) {
        cout << "8 is in the set." << endl;
    } else {
        cout << "8 is not found!" << endl;
    }

    cout << "Elements in the set: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << "\n";

    cout << "Set size: " << numbers.size() << "\n";

    numbers.clear();
    cout << "Set cleared. Size: " << numbers.size() << "\n";

    set<int> set1 = {1, 2, 3, 4, 5};
    set<int> set2 = {4, 5, 6, 7, 8};

    // Объединение множеств
    set<int> unionSet;
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
                   inserter(unionSet, unionSet.begin()));
    cout << "Union: ";
    for (int num : unionSet) {
        cout << num << " ";
    };
    cout << "\n";

    // Пересечение множеств
    set<int> intersectionSet;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                          inserter(intersectionSet, intersectionSet.begin()));
    cout << "Intersection: ";
    for (int num : intersectionSet) {
        cout << num << " ";
    };
    cout << "\n";

    // Разность множеств
    set<int> differenceSet;
    set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
                        inserter(differenceSet, differenceSet.begin()));
    cout << "Difference (set1 - set2): ";
    for (int num : differenceSet) {
        cout << num << " ";
    };
    cout << "\n";

    return 0;
}
