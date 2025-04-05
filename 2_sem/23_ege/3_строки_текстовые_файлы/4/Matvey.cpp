#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream inputFile("4.txt");

    string line;
    int count = 0;

    while (getline(inputFile, line)) {
        int countX = 0, countS = 0;
        for (int c=0; c<line.size();c++)
		{
            if (line[c] == 'X')
			{
                countX++;
            }
			if (line[c] == 'S')
			{
                countS++;
            }
        }

        if (countX == countS) {
            count++;
        }
    }

    cout << count << std::endl;

    inputFile.close();
    return 0;
}
