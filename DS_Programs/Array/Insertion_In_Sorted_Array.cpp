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
        if (arr[i] > element)
        {
            indx = i;
            break;
        }
    }

    for (int i = n; i >= indx; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[indx] = element;

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
