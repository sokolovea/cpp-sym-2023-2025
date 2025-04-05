#include <stdio.h>
#define MAX_N 1000
int main()
{
    int array[10];
    int k;
    int v;
    int z;
    // int array[10] = {1, 2, 3, 4, 5};
    // int array[10] = {0};
    for (int i = 0; i <= 9; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    for (int i = 0; i <= 9; i++)
    {
        array[i] = 0;
    }

    for (int i = 0; i <= 9; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    for (int i = 0; i <= 9; i++)
    {
        array[i] = i;
    }

    printf("%d\n", array[0]);
    printf("%d\n", *array); //арифметика указателей
    printf("%d\n", array[1]);
    printf("%d\n", *(array + 1));

    for (int i = 0; i <= 9; i++)
    {
        printf("%d ", *(array + i));
    }
    printf("\n");

    char myString[50];
    myString[0] = 'H';
    myString[1] = 'e';
    myString[2] = 'l';
    myString[3] = 'l';
    myString[4] = 'o';
    myString[5] = '!';
    myString[6] = '\n';
    myString[7] = 0;
    myString[8] = 'W'; //Не будет напечатано
    printf("%s\n", myString);


    int my_array[MAX_N]; //Допустимо при не очень большом MAX_N
    int n;
    scanf("%d", &n);
    int another_array[n]; //VLA, очень опасно использовать, поскольку n пользователь может ввести очень большим
    printf("I am OK!\n");
}