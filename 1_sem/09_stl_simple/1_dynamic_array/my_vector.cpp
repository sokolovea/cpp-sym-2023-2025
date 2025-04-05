#include "my_vector.h"

void init(MyVector& vec, int initialCapacity) {
    vec.data = new int[initialCapacity];
    vec.size = 0;
    vec.capacity = initialCapacity;
}

void resize(MyVector& vec, int newCapacity) {
    int* newData = new int[newCapacity];
    for (int i = 0; i < vec.size; ++i) {
        newData[i] = vec.data[i];
    }
    delete[] vec.data;
    vec.data = newData;
    vec.capacity = newCapacity;
}

void push_back(MyVector& vec, int value) {
    if (vec.size == vec.capacity) {
        resize(vec, vec.capacity * 2);
    }
    vec.data[vec.size] = value;
    vec.size += 1;
}

int get_size(const MyVector& vec) {
    return vec.size;
}

void pop_back(MyVector& vec) {
    if (vec.size != 0) {
        vec.size--;
    }
}

void destroy(MyVector& vec) {
    delete[] vec.data;
    vec.data = nullptr;
    vec.size = 0;
    vec.capacity = 0;
}

int get_element(const MyVector& vec, int index, bool& isError) {
    if (index < 0 || index >= vec.size) {
        isError = true;
        return 0; //не совсем хорошо
    }
    isError = false;
    return vec.data[index];
}
