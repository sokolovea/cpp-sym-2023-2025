#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
	
	ifstream fin;
    fin.open("1.txt");
	string s;
	int count = 0;
	while (!fin.eof())
    {
        fin >> s; // getline(fin, s);
        cout << s << endl;
        for(int i = 2; i < s.size(); i++) {
			if (s[i - 2] == 'K' && s[i - 1] == 'O' && s[i] == 'T')
			{
				count++;
			}
		}
    }

	cout << count;
	return 0;
}
