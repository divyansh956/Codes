#include <bits/stdc++.h>
using namespace std;

bool sumK(int ind, int k, vector<int> arr)
{
    if (k == 0)
    {
        return true;
    }

    if (ind == 0)
    {
        return arr[0] == k;
    }

    bool take = false;

    if (k >= arr[ind])
    {
        take = sumK(ind - 1, k - arr[ind], arr);
    }

    bool notTake = sumK(ind - 1, k, arr);

    return take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    return sumK(n - 1, k, arr);
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

        cout << subsetSumToK(n, k, nums) << endl;
    }
}

/******************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

bool sumK(int ind, int k, vector<int> arr, vector<vector<int>> &dp)
{
    if (k == 0)
    {
        return true;
    }

    if (ind == 0)
    {
        return arr[0] == k;
    }

    if (dp[ind][k] != -1)
    {
        return dp[ind][k];
    }

    bool take = false;

    if (k >= arr[ind])
    {
        take = sumK(ind - 1, k - arr[ind], arr, dp);
    }

    bool notTake = sumK(ind - 1, k, arr, dp);

    return dp[ind][k] = take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return sumK(n - 1, k, arr, dp);
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

        cout << subsetSumToK(n, k, nums) << endl;
    }
}

/******************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool take = false;

            if (target >= arr[ind])
            {
                take = dp[ind-1][target-arr[ind]];
            }

            bool notTake = dp[ind-1][target];

            dp[ind][target] = take || notTake;
        }
    }

    return dp[n-1][k];
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

        cout << subsetSumToK(n, k, nums) << endl;
    }
}

/******************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<bool> prevRow(k + 1, 0);
    prevRow[0] = true;
    prevRow[arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        vector<bool> curr(k + 1, 0);
        curr[0] = true;

        for (int target = 1; target <= k; target++)
        {
            bool take = false;

            if (target >= arr[ind])
            {
                take = prevRow[target - arr[ind]];
            }

            bool notTake = prevRow[target];

            curr[target] = take | notTake;
        }
        prevRow = curr;
    }

    return prevRow[k];
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

        cout << subsetSumToK(n, k, nums) << endl;
    }
}
