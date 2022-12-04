#include <bits/stdc++.h>
using namespace std;

void determinant(int a[][10], int row, int col)
{
    int determinant = a[0][0] * ((a[1][1] * a[2][2]) - (a[2][1] * a[1][2])) -
                      a[0][1] * (a[1][0] * a[2][2] - a[2][0] * a[1][2]) + a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1]);
    cout << "Determinant of Array : " << determinant << endl;
}

void transpose(int a[][10], int row, int col)
{
    cout << "Array After Transpose :\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
}

void multiply(int a[][10], int row, int b[][10], int col)
{
    int sum = 0, c[10][10];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            for (int k = 0; k < row; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
            sum = 0;
        }
    }
    cout << "Array After Multiplication :\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}

void subtract(int a[][10], int row, int b[][10], int col)
{
    int c[10][10];
    cout << "Matrix After Subtraction :\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}

void add(int a[][10], int row, int b[][10], int col)
{
    int c[10][10];
    cout << "Matrix After Addition :\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int row, col;
    int a[10][10], b[10][10], c[10][10];
    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> b[i][j];
        }
    }
    
    add(a, row, b, col);
    subtract(a, row, b, col);
    multiply(a, row, b, col);
    transpose(a, row, col);
    determinant(a, row, col);
}
