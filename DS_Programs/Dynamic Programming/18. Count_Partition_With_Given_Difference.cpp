#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int sumK(int ind, int k, vector<int> arr)
{
    if (k < 0)
    {
        return 0;
    }

    if (ind == 0)
    {
        if (k == 0 && arr[0] == 0)
        {
            return 2;
        }

        if (k == 0 || k == arr[0])
        {
            return 1;
        }

        return 0;
    }

    int take = sumK(ind - 1, k - arr[ind], arr);

    int notTake = sumK(ind - 1, k, arr);

    return (take + notTake) % mod;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();

    return sumK(n - 1, tar, num);
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int total = 0;
    for (auto x : arr)
    {
        total += x;
    }

    if (total - d < 0 || (total - d) % 2 != 0)
    {
        return 0;
    }

    return findWays(arr, (total - d) / 2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;

        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        cout << countPartitions(n, d, nums) << endl;
    }
}

/****************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int sumK(int ind, int k, vector<int> arr, vector<vector<int>> &dp)
{
    if (k < 0)
    {
        return 0;
    }

    if (ind == 0)
    {
        if (k == 0 && arr[0] == 0)
        {
            return 2;
        }

        if (k == 0 || k == arr[0])
        {
            return 1;
        }

        return 0;
    }

    if (dp[ind][k] != -1)
    {
        return dp[ind][k];
    }

    int take = sumK(ind - 1, k - arr[ind], arr, dp);

    int notTake = sumK(ind - 1, k, arr, dp);

    return dp[ind][k] = (take + notTake) % mod;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));

    return sumK(n - 1, tar, num, dp);
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int total = 0;
    for (auto x : arr)
    {
        total += x;
    }

    if (total - d < 0 || (total - d) % 2 != 0)
    {
        return 0;
    }

    return findWays(arr, (total - d) / 2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;

        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        cout << countPartitions(n, d, nums) << endl;
    }
}

/****************************************************************************************************/



#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int findWays(vector<int> &num, int tar)
{
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    if (num[0] <= tar)
    {
        dp[0][num[0]] = 1;
    }

    if (num[0] == 0)
    {
        dp[0][0] = 2;
    }
    else
    {
        dp[0][0] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int k = 0; k <= tar; k++)
        {
            int pick = 0;
            if (k >= num[ind])
            {
                pick = dp[ind - 1][k - num[ind]];
            }

            int notPick = dp[ind - 1][k];

            dp[ind][k] = (pick + notPick) % mod;
        }
    }
    return dp[n - 1][tar];
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int total = 0;
    for (auto x : arr)
    {
        total += x;
    }

    if (total - d < 0 || (total - d) % 2 != 0)
    {
        return 0;
    }

    return findWays(arr, (total - d) / 2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;

        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        cout << countPartitions(n, d, nums) << endl;
    }
}

/****************************************************************************************************/



#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int findWays(vector<int> &num, int tar)
{
    int n = num.size();

    vector<int> prevRow(tar + 1, 0);

    for (int i = 0; i < n; i++)
    {
        prevRow[0] = 1;
    }

    if (num[0] <= tar)
    {
        prevRow[num[0]] = 1;
    }

    if (num[0] == 0)
    {
        prevRow[0] = 2;
    }
    else
    {
        prevRow[0] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        vector<int> curr(tar + 1, 0);

        for (int k = 0; k <= tar; k++)
        {
            int pick = 0;
            if (k >= num[ind])
            {
                pick = prevRow[k - num[ind]];
            }

            int notPick = prevRow[k];

            curr[k] = (pick + notPick) % mod;
        }
        prevRow = curr;
    }
    return prevRow[tar];
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int total = 0;
    for (auto x : arr)
    {
        total += x;
    }

    if (total - d < 0 || (total - d) % 2 != 0)
    {
        return 0;
    }

    return findWays(arr, (total - d) / 2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;

        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        cout << countPartitions(n, d, nums) << endl;
    }
}
