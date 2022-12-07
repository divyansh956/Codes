#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }
    int k = totalSum;

    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    if (arr[0] <= k)
    {
        dp[0][arr[0]] = true;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool take = false;

            if (target >= arr[ind])
            {
                take = dp[ind - 1][target - arr[ind]];
            }

            bool notTake = dp[ind - 1][target];

            dp[ind][target] = take || notTake;
        }
    }

    int mn = INT_MAX;
    for (int s1 = 0; s1 <= totalSum / 2; s1++)
    {
        if (dp[n - 1][s1] == true)
        {
            mn=min(mn,abs(totalSum-s1*2));
        }
    }
    return mn;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        cout << minSubsetSumDifference(nums, n) << endl;
    }
}
