#include <iostream>
#include <string>

using namespace std;

class Man
{
private:
    int age;
    string name;

public:
    Man() {}
    Man(int age, string name)
    {
        this->age = age;
        this->name = name;
    }

    void setName(string name) { this->name = name; }

    string getName() { return this->name; }

    void setAge(int age) { this->age = age; }

    int getAge() { return this->age; }

    void printInfo()
    {
        cout << "My name is " << this->getName() << endl;
        cout << "My age is " << this->getAge() << endl;
    }
    ~Man() {
        cout << "Destructor!" << endl;
    }
};

int main() {
    Man student = Man(21, "Egor");
    Man teacher = Man();
    teacher.setAge(40);
    teacher.setName("Alexey");
    student.printInfo();
    teacher.printInfo();

    {
        Man guest = Man(32, "Guest");
        guest.printInfo();
    }
}
