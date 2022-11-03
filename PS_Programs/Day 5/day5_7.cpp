#include <bits/stdc++.h>
using namespace std;

void reverse(int nums[], int n)
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        swap(nums[s++], nums[e--]);
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
        reverse(nums, n);
        for (int i = 0; i < n; i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
