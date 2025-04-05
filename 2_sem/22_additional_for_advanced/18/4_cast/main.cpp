#include <iostream>
#include <typeinfo>

using namespace std;

class Base {
public:
    virtual void display() const {
        cout << "Базовый класс" << endl;
    }
};

class Inherited : public Base {
public:
    int a = 5;
    void display() const override {
        cout << "Наследуемый класс" << endl;
    }
    void additional()
    {
        cout << "Новый метод; a = " << a << endl;
    }
};

void useStaticCast() {
    cout << "--- static_cast ---" << endl;
    Base* base = new Base(); // Сделать полиморфным для проверки
    Inherited* inherited = static_cast<Inherited*>(base); // Приведение вниз по иерархии
    inherited->display();
    inherited->additional(); // Что произойдёт?
    
    double pi = 3.14;
    int intPi = static_cast<int>(pi); // (int)
    cout << "intPi = " << intPi << endl;
    
    delete base;
}

void useDynamicCast() {
    cout << "--- dynamic_cast ---" << endl;
    Base* base = new Inherited(); // Полиморфное создание объекта
    Inherited* inherited = dynamic_cast<Inherited*>(base); // Безопасное приведение вниз по иерархии
    if (inherited) {
        cout << "dynamic_cast сработал!" << endl;
        inherited->display();
        inherited->additional();
    } else {
        cout << "dynamic_cast не сработал!" << endl;
    }

    Base* baseOnly = new Base();
    inherited = dynamic_cast<Inherited*>(baseOnly); // Приведение неудачное
    if (!inherited) {
        cout << "dynamic_cast ожидаемо не сработал!" << endl;
    }
    
    delete base;
    delete baseOnly;
}

void useConstCast() {
    cout << "--- const_cast  ---" << endl;
    const int constant = 42;
    const int* constPtr = &constant;
    int* modifiablePtr = const_cast<int*>(constPtr);
    *modifiablePtr = 24; // Опасно, так как изначально значение было const
    cout << "Опасно модифицированное значение: " << *modifiablePtr << endl;
}

void useReinterpretCast() {
    cout << "--- reinterpret_cast ---" << endl;
    int num = 65;
    char* charPtr = reinterpret_cast<char*>(&num); // Преобразование указателя на int к указателю на char
    cout << "int " << num << " как char = " << *charPtr << endl; // 'A'

    // Пример использования reinterpret_cast с функциями
    void(*funcPtr)() = reinterpret_cast<void(*)()>(charPtr); // Преобразование указателя на char к указателю на функцию
    // Вызов funcPtr здесь будет некорректным и приведет к неопределенному поведению
}

int main() {
    useStaticCast();
    useDynamicCast();
    useConstCast();
    useReinterpretCast();
    return 0;
}
