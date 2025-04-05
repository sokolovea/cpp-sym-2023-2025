#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	// File
    ifstream fin;
    fin.open("17.txt");
    int* array = new int[1000000];
    int arrayLength = 0;
    while (!fin.eof())
    {
        fin >> array[arrayLength];
        arrayLength += 1;
    }
    
    //proga
    int FIndex=0, SIndex=1;
    int summax = -20001, counter=0;
    
    
	while(SIndex<arrayLength)
	{
		if( (array[FIndex]%3==0) || (array[SIndex]%3==0) )
		{
			if( (array[FIndex]+array[SIndex])>summax )
			{
				summax=array[FIndex]+array[SIndex];
			}
			counter++;
		}
		FIndex++;
		SIndex++;
	}
	
    //BlbBOD
	cout<< counter <<endl;
    cout<< summax <<endl;
    return 0;
}

