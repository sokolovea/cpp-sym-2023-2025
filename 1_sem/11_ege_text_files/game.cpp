#include <iostream>

using namespace std;

bool game(int stonesCount, int i) {
    if (i == 3) {
        return (stonesCount >= 68); 
    }
    if (stonesCount >= 68) {
        return 0;
    }
    return game(stonesCount + 1, i + 1) || game(stonesCount + 4, i + 1)
        || game(stonesCount * 5, i + 1);
}

int main()
{
    for (int s = 1; s <= 67; s++) {
        cout << s << "; " << game(s, 1) << endl;
    }
}
