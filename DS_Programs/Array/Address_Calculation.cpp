#include <iostream>
using namespace std;
int main()
{
    cout << "Enter 1 for 1D array, 2 for 2D array and 3 for 3D array\n";
    int dim;
    cin >> dim;

    if (dim == 1)
    {
        int size1;
        cin >> size1;
        int b[size1];
        int m, y;
        cin >> m;
        cout << "Base address: " << (long)b << endl;
        cout << "Actual address: " << (long)&b[m] << endl;
        y = m - 0;
        cout << y << endl;
        cout << "Calculated address:" << long(b + y) << endl;
        cout << endl;
    }
    else if (dim == 2)
    {
        int size1, size2;
        cin >> size1 >> size2;
        int a[size1][size2];
        int i, j, x;
        cin >> i >> j;
        cout << "Base address: " << (long)a[0] << endl;
        cout << "Actual address: " << (long)&a[i][j] << endl;
        x = (i - 0) * (size1 - 0 + 1) + (j - 0);
        cout << x << endl;
        cout << "Calculated address:" << long(a[0] + x) << endl;
        cout << endl;
    }
    else if (dim == 3)
    {
        int size1, size2, size3;
        cin >> size1 >> size2 >> size3;
        int c[size1][size2][size3];
        int g, f, h, z;
        cin >> g >> f >> h;
        cout << "Base address: " << (long)c[0][0] << endl;
        cout << "Actual address: " << (long)&c[g][f][h] << endl;
        z = (g - 0) * (size2 - 0 + 1) * (size1 - 0 + 1) + (f - 0) * (size2 - 0 + 1) + (h - 0);
        cout << z << endl;
        cout << "Calculated address:" << long(c[0][0] + z) << endl;
    }
    else
    {
        cout << "Please select a dimension less than or equal to 3\n";
    }
    return 0;
}
