#include <iostream>

using namespace std;

int gcd1(int a, int b) {
    if (a == b)
        return a;
    if (a > b)
        return gcd1(a-b, b);
    return gcd1(a, b-a);
}

int gcd2(int a, int b) {
    if (a % b == 0)
        return b;
    if (b % a == 0)
        return a;
    if (a > b)
        return gcd2(a%b, b);
    return gcd2(a, b%a);
}

int main()
{
    cout << gcd1(16, 36) << endl;
//    cout << gcd1(2, 10000) << endl;
    cout << gcd2(2, 10000) << endl;
}