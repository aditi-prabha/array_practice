#include <iostream>
using namespace std;

#include "solution.h"
void spiralPrint(int **input, int nRows, int nCols)
{
    // Write your code here
    int rs = 0, re = nRows - 1, cs = 0, ce = nCols - 1;
    if (nRows == 1)
    {
        for (int j = cs; j < ce + 1; j++)
        {
            cout << input[rs][j] << " ";
        }
    }
    else if (nCols == 1)
    {
        for (int j = rs; j < re + 1; j++)
        {
            cout << input[j][ce] << " ";
        }
    }
    else
    {
      int count = 0;
        for (int i = 0; count < nRows * nCols; i++)
        {
            if (i % 4 == 0)
            {
                for (int j = cs; j < ce + 1; j++)
                {
                    cout << input[rs][j] << " ";
                    count++;
                }
                rs++;
            }
            else if (i % 4 == 1)
            {
                for (int j = rs; j < re + 1; j++)
                {
                    cout << input[j][ce] << " ";
                    count++;
                }
                ce--;
            }
            else if (i % 4 == 2)
            {
                for (int j = ce; j >= cs; j--)
                {
                    cout << input[re][j] << " ";
                    count++;
                }
                re--;
            }
            else if (i % 4 == 3)
            {
                for (int j = re; j >= rs; j--)
                {
                    cout << input[j][cs] << " ";
                    count++;
                }
                cs++;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int row, col;
        cin >> row >> col;
        int **matrix = new int *[row];

        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        spiralPrint(matrix, row, col);

        for (int i = 0; i < row; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        cout << endl;
    }
}
