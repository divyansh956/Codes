#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int *ptr = &nums[0];

    cout << "Address: ";
    for (int i = 0; i < n; i++)
    {
        cout << unsigned((ptr + i)) << " ";
    }
    cout << endl;

    cout << "Value: ";
    for (int i = 0; i < n; i++)
    {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    /* for (int i = 0; i < n; i++)
    {
        cout << *(nums + i) << " ";
    }
    cout << endl; */
}
