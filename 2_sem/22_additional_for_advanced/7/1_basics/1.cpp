#include <iostream>
#include <thread>
#include <string>

using namespace std;

void f(string name) {
    cout << "Hello, " << name << "!" << endl;
    for (int i = 0; i <= 300000000; i++) {;}
}

int main() {
    std::thread myThread1(f, "Egor"); // + ссылочный тип
    std::thread myThread2(f, "Yaroslav");

    myThread1.join(); //не забыть попробовать detach()
    myThread2.join();
    cout << "The end!" << endl;

    return 0;
}