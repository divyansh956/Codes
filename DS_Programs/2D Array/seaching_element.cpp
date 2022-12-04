#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter Rows and Coloumns of Array = ";
    cin >> n >> m;

    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "Matrix is :\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int x;
    cout << "Enter Element to be Found = ";
    cin >> x;

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == x)
            {
                k = 0;
                cout << "Element Found At " << i + 1 << " Row, " << j + 1 << " Coloumn" << endl;
                k++;
                break;
            }
        }
    }

    if (k == 0)
    {
        cout << "Element Not Found" << endl;
    }

    return 0;
}
