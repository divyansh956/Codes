#include <bits/stdc++.h>
using namespace std;

long findWays(int ind, int k, int *nums)
{
    if (ind == 0)
    {
        return (k % nums[ind] == 0);
    }

    long notTake = findWays(ind - 1, k, nums);

    long take = 0;
    if (nums[ind] <= k)
    {
        take = findWays(ind, k - nums[ind], nums);
    }

    return take + notTake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    return findWays(n - 1, value, denominations);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int nums[n];
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        cout << countWaysToMakeChange(nums, n, k) << endl;
    }
}

/****************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

long findWays(int ind, int k, int *nums, vector<vector<long>> &dp)
{
    if (ind == 0)
    {
        return (k % nums[ind] == 0);
    }

    if (dp[ind][k] != -1)
    {
        return dp[ind][k];
    }

    long notTake = findWays(ind - 1, k, nums, dp);

    long take = 0;
    if (nums[ind] <= k)
    {
        take = findWays(ind, k - nums[ind], nums, dp);
    }

    return dp[ind][k] = take + notTake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));

    return findWays(n - 1, value, denominations, dp);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int nums[n];
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        cout << countWaysToMakeChange(nums, n, k) << endl;
    }
}

/****************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, 0));
    for (int k = 0; k <= value; k++)
    {
        dp[0][k] = (k % denominations[0] == 0);
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int k = 0; k <= value; k++)
        {
            long notTake = dp[ind - 1][k];

            long take = 0;
            if (denominations[ind] <= k)
            {
                take = dp[ind][k - denominations[ind]];
            }

            dp[ind][k] = take + notTake;
        }
    }

    return dp[n - 1][value];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int denominators[n];
        for (int i = 0; i < n; i++)
        {
            cin >> denominators[i];
        }

        cout << countWaysToMakeChange(denominators, n, k) << endl;
    }
}

/****************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<long> prev(value + 1, 0);
    for (int k = 0; k <= value; k++)
    {
        prev[k] = (k % denominations[0] == 0);
    }

    for (int ind = 1; ind < n; ind++)
    {
        vector<long> curr(value + 1, 0);

        for (int k = 0; k <= value; k++)
        {
            long notTake = prev[k];

            long take = 0;
            if (denominations[ind] <= k)
            {
                take = curr[k - denominations[ind]];
            }

            curr[k] = take + notTake;
        }
        prev = curr;
    }
    return prev[value];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int denominators[n];
        for (int i = 0; i < n; i++)
        {
            cin >> denominators[i];
        }

        cout << countWaysToMakeChange(denominators, n, k) << endl;
    }
}
