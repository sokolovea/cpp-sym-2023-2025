#include <cstdint>
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

const int64_t count = 1e8;

using namespace std;
using namespace chrono;

void sum(int64_t& result) {
    for (int64_t i = 0; i < count; i++) {
        result++;
    }
}

int main()
{
    //Однопоточная версия
    int64_t resultSingle = 0;
    auto start = high_resolution_clock::now();

    for (int64_t i = 0; i < count * 2; i++) {
        resultSingle++;
    }

    auto end = high_resolution_clock::now();
    auto durationSingle = duration_cast<milliseconds>(end - start).count();

    //Параллельная версия (alignas(4096))
    int64_t resultParallel = 0;
    start = high_resolution_clock::now();

    thread t1(sum, ref(resultParallel));
    thread t2(sum, ref(resultParallel));

    t1.join();
    t2.join();
    end = high_resolution_clock::now();
    auto durationParallel = duration_cast<milliseconds>(end - start).count();
    cout << "Result single = " << resultSingle <<" (" << durationSingle << " ms.)" << endl;
    cout << "Result parallel = " << resultParallel <<" (" << durationParallel << " ms.)" << endl;
    return 0;
}


// void sumCorrect(int64_t& result, mutex& mtx) {
//     for (size_t i = 0; i < count; ++i) {
//         lock_guard<mutex> lock(mtx);
//         result++;
//     }
// }
