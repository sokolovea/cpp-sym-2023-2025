#include <iostream>
#include <string>

using namespace std;

class Man
{
private:
    int age;
    string name = string();

public:

    Man(int age, string name)
    {
        cout << "Man constructor!" << endl;
        this->age = age;
        this->name = name;
    }

    void setName(string name) { this->name = name; }

    string getName() const { return this->name; }

    void setAge(int age) { this->age = age; }

    int getAge() const { return this->age; }

    virtual ~Man() {
        cout << "Man Destructor!" << endl;
    }
};

class Student : public Man {
private:
    int grade;
public:
    Student(int age, string name, int grade) : Man(age, name)
    {
        cout << "Student constructor!" << endl;
        this->grade = grade;
    }

    int getScholarship() const
    {
        return 5000;
    }

    ~Student()
    {
        cout << "Student destructor!" << endl;
    }
};

class Teacher : public Man {
    int experience;
public:
    Teacher(int age, string name, int experience) : Man(age, name)
    {
        cout << "Teacher constructor!" << endl;
        this->experience = experience;
    }

    int getSalary() const
    {
        return 30000 + this->experience * 2500;
    }

    ~Teacher()
    {
        cout << "Teacher destructor!" << endl;
    }
};

std::ostream& operator << (std::ostream& stream, const Man& man)
{
    stream << "My name is " << man.getName() << endl;
    stream << "My age is " << man.getAge();
    return stream;
}



int main() {
    Student student = Student(20, "Egor", 3);
    Teacher teacher = Teacher(40, "Alexey", 15);
    cout << "---" << endl << student.getScholarship() << endl;
    cout << "---" << endl << teacher.getSalary() << endl << "---" << endl;
    cout << student << endl << teacher << endl; 
}