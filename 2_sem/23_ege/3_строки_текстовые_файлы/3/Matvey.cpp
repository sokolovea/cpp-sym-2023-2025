#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
	
	ifstream file("3.txt");
	string s;
	getline(file, s);
    file.close();
    
    
	int count = 1;int CCount=0;
	
        for(int f=0; f<(s.size()-1); f++)
        {
                if(s[f+1]==s[f])// ������� ��� ����� ������������������
                {
                    count++;
                }
                else// ����� ������������������ �����������,���������� ���������� �
                    // � ������ ������������ �������������������.
				{
                     if(count>=CCount)
                     {
                        CCount=count;
                     }                                      
					 count=1;
			    }
                
        }
    cout << CCount << endl;
}
