#include <iostream>
#include <string>
#include <limits>

using namespace std;
int main() {
    string name = "Ivan";
    string surname = string("Ivanov");
    auto fullName = name + " " + surname;
    cout << "fullName.length() = " << fullName.length() << endl;
    cout << "fullName[3] = " << fullName[3] << endl;

    cout.setf(cout.boolalpha);
    cout << "name == surname: " << (name == surname) << endl;
    cout << "\"abcdef\" > \"abcdaaaaaaaa\": " << (string("abcdef") > string("abcdaaaaaaaa")) << endl;

    fullName.insert(11, " Ivanovich!");
    fullName = fullName.substr(5, 13);
    cout << "fullName = " << fullName << endl;
    cout << fullName.find("ov") << endl;
    cout << fullName.find("ov", 7) << endl;
    cout << fullName.find("viswdf") << endl; //string::npos
    cout << "fullName.cstr() = " << fullName.c_str() << endl;

    cout << "fullName.length() = " << fullName.length() << endl;
    cout << "fullName.capacity() = " << fullName.capacity() << endl;
    
    for (int i = 1; i <= 2; i++)
    {
        fullName.append("123456789");
        cout << "fullName.length() = " << fullName.length() << endl;
        cout << "fullName.capacity() = " << fullName.capacity() << endl;
    }
}