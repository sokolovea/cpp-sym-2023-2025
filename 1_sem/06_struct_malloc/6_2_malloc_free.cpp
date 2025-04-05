#include <stdio.h>
#include <stdlib.h>

void errorMessage()
{
    printf("Error in malloc()!\n");
}

int main()
{
    int n = 100;
    int* array = NULL;
    array = (int*)malloc(n * sizeof(int));
    if (array == NULL)
    {
        errorMessage();
        return 1;
    }
    for (int i = 0; i < n; i++) {
        array[i] = i * i;
    }
    for (int i = 0; i < n; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }

    free(array);
    array = NULL;

    while (1) {
        printf("input count of MB for malloc()\n");
        int code = scanf("%d", &n);
        if (code != 1 || n == -1)
        {
            free(array);
            return 2;
        }
        array = (int*)malloc(n * 1024 * 1024);
        if (array == NULL)
        {
            errorMessage();
        } else {
            for (int i = 0; i < n * 1024 * 1024 / sizeof(int) ; i++) {
                array[i] = 0;
            }
            printf("OK!\n");
        }
        scanf("%d", &n);
        free(array);
        array = NULL;
    }

}