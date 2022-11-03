#include <bits/stdc++.h>
using namespace std;

void countSort(int nums[], int n)
{
    int mx = *max_element(nums, nums + n);
    int idx[mx + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        idx[nums[i]]++;
    }

    for (int i = 1; i < mx + 1; i++)
    {
        idx[i] = idx[i] + idx[i - 1];
    }

    int ans[n];
    for (int i = n - 1; i >= 0; i--)
    {
        ans[--idx[nums[i]]] = nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        nums[i]=ans[i];
    }
    
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

    countSort(nums, n);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
