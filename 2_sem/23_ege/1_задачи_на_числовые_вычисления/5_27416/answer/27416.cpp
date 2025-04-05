#include <iostream>

using namespace std;

bool game(int heap1, int heap2, int step)
{
    if (heap1 + heap2 >= 77 && step < 3)
    {
        return false;
    }
    if (step == 3)
    {
        return (heap1 + heap2 >= 77);
    }
    return game(heap1 + 1, heap2, step + 1) || game(heap1, heap2 * 2, step + 1);

}

int main()
{
    for (int i = 1; i <= 28; i++)
    {
        cout << i << ": " << game(7, i, 1) << endl;
    }
}
