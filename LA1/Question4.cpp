#include <iostream>
using namespace std;

const int MAX = 10;

void printMatrix(int mat[][MAX]) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void multiplyMatrices(int mat1[][MAX], int mat2[][MAX], int result[][MAX]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transposeMatrix(int mat[][MAX], int result[][MAX]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                result[i][j] = mat[j][i];
            }
        }
    }
}

int main() {

    // Create
	int size = 4;
    int arr[] = {1, 3, 5, 7};

    // Reverse Array
    int start = 0;
    int end = size - 1;

    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    cout << "Print: " << endl;
	for (int i = 0; i <= size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    // Matrix Mutiplication
    int mat1[MAX][MAX] = {{1, 2}, {3, 4}};
    int mat2[MAX][MAX] = {{5, 6}, {7, 8}};
    int result[MAX][MAX] = {{0, 0}, {0, 0}};

    multiplyMatrices(mat1, mat2, result);
    printMatrix(result);

    cout << endl;

    // Transpose
    transposeMatrix(mat1, result);
    printMatrix(result);

    return 0;
}
