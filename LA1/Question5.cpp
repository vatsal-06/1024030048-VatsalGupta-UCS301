#include <iostream>
using namespace std;

const int MAX = 10;

void sumRowColumn(int mat[][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < cols; j++)
        {
            rowSum += mat[i][j];
        }
        cout << "Sum of row " << i + 1 << ": " << rowSum << endl;
    }

    cout << endl;

    for (int j = 0; j < cols; j++)
    {
        int colSum = 0;
        for (int i = 0; i < rows; i++)
        {
            colSum += mat[i][j];
        }
        cout << "Sum of column " << j + 1 << ": " << colSum << endl;
    }
}

int main()
{
    int mat1[MAX][MAX] = {{1, 2}, {3, 4}};
    sumRowColumn(mat1, 2, 2);
}
