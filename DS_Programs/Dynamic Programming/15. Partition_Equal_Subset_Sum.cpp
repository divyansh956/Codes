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

bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    if (sum % 2 != 0)
    {
        return false;
    }

    return sumK(n - 1, sum / 2, arr);
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

        cout << canPartition(nums, n) << endl;
    }
}

/****************************************************************************************************/


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

bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    if (sum % 2 != 0)
    {
        return false;
    }

    vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));

    return sumK(n - 1, sum / 2, arr, dp);
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

        cout << canPartition(nums, n) << endl;
    }
}

/****************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    if (sum % 2 != 0)
    {
        return false;
    }

    vector<vector<bool>> dp(n, vector<bool>(sum / 2 + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= sum / 2; target++)
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

    return dp[n - 1][sum / 2];
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

        cout << canPartition(nums, n) << endl;
    }
}

/****************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    if (sum % 2 != 0)
    {
        return false;
    }

    vector<bool> prevRow(sum / 2 + 1, 0);
    prevRow[0] = true;
    prevRow[arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        vector<bool> curr(sum / 2 + 1, 0);
        curr[0] = true;

        for (int target = 1; target <= sum / 2; target++)
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

    return prevRow[sum / 2];
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

        cout << canPartition(nums, n) << endl;
    }
}
