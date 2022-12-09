#include <bits/stdc++.h>
using namespace std;

int sumK(int ind, int k, vector<int> arr)
{
    if (k == 0)
    {
        return 1;
    }

    if (k < 0)
    {
        return 0;
    }

    if (ind == 0)
    {
        return arr[0] == k;
    }

    int take = sumK(ind - 1, k - arr[ind], arr);

    int notTake = sumK(ind - 1, k, arr);

    return take + notTake;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();

    return sumK(n - 1, tar, num);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        cout << findWays(nums, k) << endl;
    }
}

/****************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int sumK(int ind, int k, vector<int> arr, vector<vector<int>> &dp)
{
    if (k == 0)
    {
        return 1;
    }

    if (ind == 0)
    {
        return arr[0] == k;
    }

    if (dp[ind][k] != -1)
    {
        return dp[ind][k];
    }
 
    int take = 0;

    if (arr[ind] <= k)
    {
        take = sumK(ind - 1, k - arr[ind], arr, dp);
    }

    int notTake = sumK(ind - 1, k, arr, dp);

    return dp[ind][k] = take + notTake;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));

    return sumK(n - 1, tar, num, dp);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        cout << findWays(nums, k) << endl;
    }
}

/****************************************************************************************************/
