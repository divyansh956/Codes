#include <bits/stdc++.h>
using namespace std;

void swapAlter(int nums[], int n)
{
    int s = 0, e = 1;
    while (e < n)
    {
        swap(nums[s], nums[e]);
        s += 2;
        e += 2;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int nums[n];
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        swapAlter(nums, n);
        for (int i = 0; i < n; i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
