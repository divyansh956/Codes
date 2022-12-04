#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int a = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > a)
        {
            a = arr[i];
        }
    }

    int DAT[a + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        DAT[arr[i]]++;
    }

    cout << "Repeated Elements: ";
    for (int i = 0; i <= a; i++)
    {
        if (DAT[i] > 1)
            cout << i << " ";
    }

    cout << endl
         << "Non-Repeated Elements: ";
    for (int i = 0; i <= a; i++)
    {
        if (DAT[i] == 1)
            cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
