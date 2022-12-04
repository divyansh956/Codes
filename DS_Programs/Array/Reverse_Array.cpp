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

    int a = 0, b = n - 1;
    while (a <= b)
    {
        int temp = arr[a];
        arr[a] = arr[b];
        a = a + 1;
        arr[b] = temp;
        b = b - 1;
    }

    cout << "The reversed array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
