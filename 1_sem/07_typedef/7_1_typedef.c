#include <stdio.h>
#include <stdlib.h>

struct Point2D {
    float x;
    float y;
};

typedef struct Point3D {
    struct Point2D p;
    float z;
};

// void initializeArray(struct {struct {float x; float y;}; float z;} *array[3][2][2]); //анонимные структуры, только C
// void initializeArray(struct Point3D * array[3][2][2]);

// typedef struct {struct {float x; float y;}; float z;} ComplexArray[3][2][2];
typedef struct Point3D* ComplexArray[3][2][2];
void initializeArray(ComplexArray array);
void printArray(ComplexArray array);

int main(void) {
    // Принудительное преобразование типа
    ComplexArray myArray;
    initializeArray(myArray);
    printArray(myArray);
    // Принудительное преобразование типа
    // struct {struct {float x; float y;}; float z;}* a[3][2][2];
    // ComplexArray* b = (ComplexArray*)&a;
    // initializeArray(*b);
    // printArray(*b);
}

void initializeArray(ComplexArray array) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                array[i][j][k] = (struct Point3D*) malloc(sizeof(struct Point3D));
                array[i][j][k]->p.x = i * 3;
                array[i][j][k]->p.y = i * 3 + j * 2;
                array[i][j][k]->z = i * 3 + j * 2 + k;
            }
        }
    }
}

void printArray(ComplexArray array) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                printf("x = %f, y = %f, z = %f\n", array[i][j][k]->p.x, array[i][j][k]->p.y, array[i][j][k]->z);
            }
        }
    }
}