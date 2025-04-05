#include <stdio.h>

int main()
{
    int a[3][4];
    int b[3][4];
    int c[3][4];
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            a[i][j] = i * 4 + j; //более простой и понятный синтаксис
            (*(b + i))[j] = i * 4 + j; //плавно переходим к арифметике указателей
            *(*(c + i) + j) = i * 4 + j;
            printf("a = %d, b = %d, c = %d\n", a[i][j], b[i][j], c[i][j]);
        }
    }

    for (int i = 0; i < 3 * 4; i++)
    {
        printf("%d ", *(*a + i));
    }
    printf("\n");
}