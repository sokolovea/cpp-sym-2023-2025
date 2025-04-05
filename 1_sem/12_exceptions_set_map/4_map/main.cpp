#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, string> myMap;

    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    //Вставка
    myMap.insert({5, "Five"});
    myMap.insert({4, "Four"});
    myMap.insert({1000000, "Million"});

    cout << "Map elements:" << endl;
    for (const auto& pair : myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    int key = 3;
    auto it = myMap.find(key);
    if (it != myMap.end()) {
        cout << "Found key " << key << ": " << it->second << endl;
    } else {
        cout << "Key " << key << " not found." << endl;
    }

    // Удаляем элемент по ключу
    myMap.erase(2);
    myMap.erase(20);

    myMap[3] += " modified";

    cout << "\nAfter erasing key 2:" << endl;
    for (const auto& pair : myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Проверка наличия ключа
    if (myMap.count(2)) {
        cout << "Key 2 is present." << endl;
    } else {
        cout << "Key 2 is not present." << endl;
    }

    if (myMap.find(2) != myMap.end()) {
        cout << "Key 2 is present." << endl;
    } else {
        cout << "Key 2 is not present." << endl;
    }

    return 0;
}
