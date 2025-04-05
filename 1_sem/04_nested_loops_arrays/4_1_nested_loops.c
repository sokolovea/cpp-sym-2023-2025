#include <stdio.h>
#include <stdbool.h>
int main()
{
    int max_a = 9;
    int max_b = 9;
    for (int a = 1; a <= max_a; a++)
    {
        for (int b = 1; b <= max_b; b++)
        {
            printf("%3d", a * b);
        }
        printf("\n");
    }

    int max_c = 9;
    for (int a = 1; a <= max_a; a++)
    {
        for (int b = 1; b <= max_b; b++)
        {
            for (int c = 1; c <= max_c; c++)
            {
                printf("%4d", a * b * c);
            }
            printf("\n");
        }
        printf("\n");
    }

    
    int height = 9;
    height = height % 2 == 0 ? height + 1: height;
    int tabulation = height / 2;
    int currentWidth = 1;

    // Верхняя часть алмаза
    for (int i = 1; i < height / 2 + 1; i++) {
        for (int j = 0; j < tabulation; j++) {
            printf(" ");
        }
        for (int j = 0; j < currentWidth; j++) {
            printf("*");
        }
        printf("\n");
        tabulation -= 1;
        currentWidth += 2;
    }

    // Средняя часть алмаза
    int width = height;
    for (int i = 1; i <= width; i++)
    {
        printf("*");
    }
    printf("\n");
    currentWidth = width - 3;

    // Нижняя часть алмаза
    for (int i = height / 2 + 1; i >= 1; i--) {
        for (int j = tabulation; j >= 0; j--) {
            printf(" ");
        }
        for (int j = currentWidth; j >= 0; j--) {
            printf("*");
        }
        printf("\n");
        tabulation += 1;
        currentWidth -= 2;
    }
  
}