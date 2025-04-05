#include <iostream>
#include <vector>

using namespace std;

//Дан массив целых чисел, нужно написать алгоритм,
//позволяющий найти сумму на полуинтервале с позиции 
//a до позиции b (включительно) за O(N)

int getSum(const vector<int>& arr, int left, int right) {
    return 0;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int left = 1, right = 3;
    cout << "Сумма: " << getSum(arr, left, right) << endl;
    return 0;
}
