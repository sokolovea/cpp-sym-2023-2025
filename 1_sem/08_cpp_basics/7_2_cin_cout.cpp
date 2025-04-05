#include <iostream>
#include <string>
#include <iomanip> //для форматирования вывода через манипуляторы

// using namespace std;

int main() {
    int a, b;
    std::cout << "Input a, b" << std::endl;
    std::cin >> a >> b;
    std::cout << "a = " << a << " b = " << b << std::endl;

    std::string line;
    std::cin.ignore(); // Игнорирование оставшегося символа новой строки после предыдущего ввода перед вызовом getline
    std::cout << "Input line (with tabs, whitespace): ";
    std::getline(std::cin, line);
    std::cout << "line = " << line << std::endl;

    //Форматированный вывод
    a = 500;
    double d = 1.238267;
    std::cout.precision(3);
    std::cout << d << "\n";
    std::cout.width(40);
    std::cout.fill('#');
    std::cout << d << "\n";
    std::cout << d << "\n";
    std::cout << std::setprecision(2) << d << "; " << std::setprecision(9) << d << std::endl;
    std::cout << d << "\n";

    //Обработка ошибок
    bool isError = false;
    std::string name;
    int age;
    do
    {
        std::cout << "Your age = " ;
        std::cin >> age;
        if (std::cin.fail()) {
            isError = true;
            std::cin.clear();
        } else {
            isError = false;
        }
        std::cin.ignore(1000, '\n');
    } while (isError);

    do
    {
        std::cout << "Your first and last name = ";
        std::getline(std::cin, name);
        if (std::cin.fail()) {
            isError = true;
            std::cin.clear();
        } else {
            isError = false;
        }
    } while (isError);
    std::cout << "Your age = " << name << ", age = " << age << std::endl;
    return 0;
}
