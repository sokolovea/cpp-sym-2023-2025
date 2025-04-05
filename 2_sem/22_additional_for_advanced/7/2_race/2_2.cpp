#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex myMutex;

void f() {
    for (int i = 0; i < 1000000; ++i) {
        // Захват мьютекса (освобождение происходит автоматически при выходе из зоны видимости, т.к. RAII)
        std::lock_guard<std::mutex> lock(myMutex);
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

