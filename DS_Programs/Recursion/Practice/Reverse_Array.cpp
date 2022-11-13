#include <bits/stdc++.h>
using namespace std;

void Reverse(int nums[], int i, int n)
{
    if (i >= n)
    {
        return;
    }
    swap(nums[i], nums[n]);
    Reverse(nums, i + 1, n - 1);
}

int main()
{
    int n;
    cin >> n;

    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Reverse(nums, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}
