#include <iostream>
#include <thread>

int counter = 0;

void f() {
    for (int i = 0; i < 1000000; ++i) {
        counter++;
    }
}

int main() {
    std::thread t1(f);
    std::thread t2(f);

    t1.join();
    t2.join();

    std::cout << "counter = " << counter << std::endl;

    return 0;
}
