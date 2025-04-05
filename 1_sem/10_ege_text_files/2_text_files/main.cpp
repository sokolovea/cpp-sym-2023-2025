#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> fileLines;
    ifstream myFileRead;
    myFileRead.open(string("war_and_peace.txt"));
    if (!myFileRead.is_open())
    {
        cout << "Can't open file!" << endl;
    }
    else
    {
        string line;
        while (getline(myFileRead, line))
        {
            //cout << line << endl;
            if (line.length() != 0) {
                fileLines.push_back(line);
            }
        }
    }

    myFileRead.close();
    sort(fileLines.begin(), fileLines.end());

    /*---------*/

    ofstream myFileWrite;
    myFileWrite.open("output.txt");
    if (!myFileWrite.is_open())
    {
        cout << "Can't open file!" << endl;
    }
    else
    {
        for (string& eachLine: fileLines) {
            myFileWrite << eachLine << std::endl;
        }
    }

    myFileWrite.close();
    return 0;
}
