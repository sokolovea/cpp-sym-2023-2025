struct MyVector {
    int* data;
    int size;        // текущий размер массива
    int capacity;    // вместимость массива
};

void init(MyVector& vec, int initialCapacity = 2);

void resize(MyVector& vec, int newCapacity);

void push_back(MyVector& vec, int value);

int get_size(const MyVector& vec);

void pop_back(MyVector& vec);

void destroy(MyVector& vec);

int get_element(const MyVector& vec, int index, bool& isError);
