#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>

void myMax(const std::vector<int>& arr, size_t start, size_t end, int& result) {
    result = *std::max_element(arr.begin() + start, arr.begin() + end);
}

int main() {
    std::vector<int> numbers;
    for (int coef = 1; coef < 10000000; coef *= 10)
    {
        for (int i = 0; i <= 100 * coef; i++)
        {
            numbers.push_back(i);
        }
        const size_t size = numbers.size();
        int max1 = 0, max2 = 0;

        auto start = std::chrono::high_resolution_clock::now();

        std::thread t1(myMax, std::ref(numbers), 0, size / 2, std::ref(max1));
        std::thread t2(myMax, std::ref(numbers), size / 2, size, std::ref(max2));

        t1.join();
        t2.join();

        int overallMax = std::max(max1, max2);

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        std::cout << "---" << std::endl;
        std::cout << overallMax << std::endl; //overallMax = недоступное i максимальное * на coeff
        std::cout << "Time taken by parallel function: " << (double)duration.count() / 1000 << " ms" << std::endl;

        start = std::chrono::high_resolution_clock::now();
        myMax(numbers, 0, size, overallMax);
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        std::cout << "Time taken by usual function: " << (double)duration.count() / 1000 << " ms" << std::endl;

        numbers.clear();
    }
    return 0;
}
