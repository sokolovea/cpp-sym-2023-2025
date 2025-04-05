#include <iostream>
#include "my_list.h"

using namespace std;

int main()
{
    cout << "Default list" << endl;
    MyList* head = init();
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 4);
    head = push(head, 5);
    cout << "Head length = " << getLength(head) << endl;
    cout << "Head values: " << endl;
    print(head);
    cout << endl << "---" << endl << endl;
    int value;
    while (pop(head, value)) {
        cout << "Pop value " << value << "!" << endl;
    }
    cout << "MyList is empty! Size = " << getLength(head) << endl;
    cout << endl << "---CRAZY MODE!!!---" << endl;
    long myListSize;
    cin >> myListSize;
    for (long i = 0; i < myListSize; i++) {
        head = push(head, i % 4096);
    }
    long calculatedlength = getLength(head);
    cout << "Head length = " << calculatedlength << endl;
    cout << "Predicted size = " << sizeof(MyList) * calculatedlength / (1024 * 1024.0) << " MB" << endl;
    cin >> myListSize;

    return 0;
}
