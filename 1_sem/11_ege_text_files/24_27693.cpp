#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
    ifstream myFile;
    int counter = 1;
    int temp = 1;
    myFile.open(string("24_27693.txt"));
    if(!myFile.is_open()) {
        cout << "Error!" << endl;
    }
    string str;
    myFile >> str;
    for(int i = 1; i < str.length() - 1; i++){
        if((str[i] == 'C') && (str[i - 1] == 'C')){
		    counter++;
            temp = max(temp, counter);
        }
        else {
            counter = 1;
        }
    }
    cout << temp;
}
