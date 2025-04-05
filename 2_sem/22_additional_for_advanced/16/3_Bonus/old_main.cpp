#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, tempNumber, minValue;
    cin >> n;
    cin >> k;
    deque<int> myDeque;
    for (int i = 0; i < n; i += 1)
    {
        cin >> tempNumber;
        myDeque.push_back(tempNumber);
        if (i >= k - 1 || i == n)
        {
            minValue = *min_element(myDeque.begin(), myDeque.end());
            myDeque.pop_front();
            cout << minValue << endl;
        }
    }
}