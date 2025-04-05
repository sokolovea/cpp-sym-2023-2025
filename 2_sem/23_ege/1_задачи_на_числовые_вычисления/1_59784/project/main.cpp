#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int max15(int* array, int length)
{
    int tempMax = -1000000;
    for (int i = 0; i < length; i++)
    {
        if (array[i] > tempMax && abs(array[i]) % 100 == 15) {
            tempMax = array[i];
        }
    }
    return tempMax;
}

int is4(int number)
{
    return (abs(number) / 1000 <= 9 && abs(number) / 1000 > 0);
}

int main()
{
    ifstream fin;
    fin.open("17.txt");
    int* array = new int[1000000];
    int arrayLength = 0;
    while (!fin.eof())
    {
        fin >> array[arrayLength];
        arrayLength += 1;
    }
    int firstIndex, secondIndex, thirdIndex;
    firstIndex = 0;
    secondIndex = 1;
    thirdIndex = 2;
    int arrayMax = max15(array, arrayLength);
    int counter = 0;
    int minSum = 10000000;
    while (thirdIndex < arrayLength)
    {
        if (array[firstIndex] + array[secondIndex] + array[thirdIndex] < arrayMax)
        {
            if (is4(array[firstIndex]) + is4(array[secondIndex]) + is4(array[thirdIndex]) == 1)
            {
                counter += 1;
                minSum = min(minSum, array[firstIndex] + array[secondIndex] + array[thirdIndex]);
            }
        }
        firstIndex++;
        secondIndex++;
        thirdIndex++;
    }
    cout << counter << endl;
    cout << minSum << endl;
    return 0;
}
