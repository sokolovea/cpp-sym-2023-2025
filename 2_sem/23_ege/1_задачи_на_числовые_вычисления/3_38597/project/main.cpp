#include <iostream>

using namespace std;

bool game(int counter, int step)
{
    if (counter >= 29 && step < 3)
    {
        return false;
    }
    if (step == 3)
    {
        return (counter >= 29);
    }
    if (step % 2 == 0)
    {
        return game(counter + 1, step + 1) || game(counter * 2, step + 1);
    }
    return game(counter + 1, step + 1) && game(counter * 2, step + 1);

}

int main()
{
    for (int i = 1; i <= 28; i++)
    {
        cout << i << ": " << game(i, 1) << endl;
    }
}
