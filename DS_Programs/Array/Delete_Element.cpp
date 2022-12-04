#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int element, indx;
    cin >> element;

    n++;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == element)
        {
            indx = i;
        }
    }

    for (int i = indx; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }

    n -= 2;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
