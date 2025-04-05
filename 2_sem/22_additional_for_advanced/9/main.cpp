#include <iostream>

using namespace std;

template<int rows, int cols>
void inputMatrix(double matrix[rows][cols]) {
    cout << "Enter the elements of the matrix " << rows << " x " << cols << ":" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

template<int rows, int cols>
void printMatrix(const double matrix[rows][cols]) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    double matrix4x4[4][4];
    inputMatrix<4, 4>(matrix4x4);
    printMatrix<4, 4>(matrix4x4);

    double matrix5x5[5][5];
    inputMatrix<5, 5>(matrix5x5);
    printMatrix<5, 5>(matrix5x5);

    return 0;
}
