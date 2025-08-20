#include <iostream>
using namespace std;

struct Triplet
{
    int row, col, value;
};

void printSparse(Triplet mat[], int n)
{
    cout << "Row Col Value" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << mat[i].row << " " << mat[i].col << " " << mat[i].value << endl;
    }
}

int transposeSparse(Triplet mat[], Triplet result[], int n)
{
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        result[idx].row = mat[i].col;
        result[idx].col = mat[i].row;
        result[idx].value = mat[i].value;
        idx++;
    }
    return idx;
}

int addSparse(Triplet A[], int nA, Triplet B[], int nB, Triplet result[])
{
    int i = 0, j = 0, k = 0;
    while (i < nA && j < nB)
    {
        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col))
        {
            result[k++] = A[i++];
        }
        else if (B[j].row < A[i].row || (B[j].row == A[i].row && B[j].col < A[i].col))
        {
            result[k++] = B[j++];
        }
        else
        {
            result[k] = A[i];
            result[k].value += B[j].value;
            k++;
            i++;
            j++;
        }
    }
    while (i < nA)
        result[k++] = A[i++];
    while (j < nB)
        result[k++] = B[j++];
    return k;
}

int multiplySparse(Triplet A[], int nA, Triplet B[], int nB, Triplet result[], int rowsA, int colsA, int colsB)
{
    int k = 0;
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            int sum = 0;
            for (int a = 0; a < nA; a++)
            {
                for (int b = 0; b < nB; b++)
                {
                    if (A[a].row == i && B[b].col == j && A[a].col == B[b].row)
                    {
                        sum += A[a].value * B[b].value;
                    }
                }
            }
            if (sum != 0)
            {
                result[k].row = i;
                result[k].col = j;
                result[k].value = sum;
                k++;
            }
        }
    }
    return k;
}

int main()
{
    // Example: 3x3 matrices
    Triplet A[4] = {{0, 0, 1}, {0, 2, 2}, {1, 1, 3}, {2, 0, 4}};
    Triplet B[4] = {{0, 1, 5}, {1, 1, 6}, {2, 0, 7}, {2, 2, 8}};
    int nA = 4, nB = 4;
    int rowsA = 3, colsA = 3, rowsB = 3, colsB = 3;

    cout << "Matrix A (Sparse):" << endl;
    printSparse(A, nA);
    cout << "Matrix B (Sparse):" << endl;
    printSparse(B, nB);

    // Transpose
    Triplet transA[10];
    int nTransA = transposeSparse(A, transA, nA);
    cout << "Transpose of A:" << endl;
    printSparse(transA, nTransA);

    // Addition
    Triplet sum[20];
    int nSum = addSparse(A, nA, B, nB, sum);
    cout << "A + B (Sparse):" << endl;
    printSparse(sum, nSum);

    // Multiplication
    Triplet prod[20];
    int nProd = multiplySparse(A, nA, B, nB, prod, rowsA, colsA, colsB);
    cout << "A * B (Sparse):" << endl;
    printSparse(prod, nProd);

    return 0;
}