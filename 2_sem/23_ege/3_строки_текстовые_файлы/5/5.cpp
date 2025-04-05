#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ifstream file("5.txt");

    string s;
    getline(file, s);
    file.close();

    replace(s.begin(), s.end(), 'A', '*');
    replace(s.begin(), s.end(), 'B', '*');
    replace(s.begin(), s.end(), 'C', '*');

    int maxCount = 1;
    int count = 1;

    cout << s << endl;

    for (int i = 1; i < s.size(); i++) {
        if (s[i-1] != '*' || s[i] != '*') {
            count++;
        }
        else
        {
            maxCount = max(maxCount, count);
            count = 1;
        }
    }

    cout << maxCount << endl;

    return 0;
}