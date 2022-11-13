#include <bits/stdc++.h>
using namespace std;

int subsequence(int nums[], int i, int n, int sum, int k)
{
    if (i == n)
    {
        if (sum == k)
        {
            return 1;
        }
        return 0;
    }

    sum += nums[i];
    int l = subsequence(nums, i + 1, n, sum, k);

    sum -= nums[i];
    int r = subsequence(nums, i + 1, n, sum, k);
    
    return l + r;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> ans;

    cout << subsequence(nums, 0, n, 0, k) << endl;
}
