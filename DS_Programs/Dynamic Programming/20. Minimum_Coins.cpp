#include <bits/stdc++.h>
using namespace std;

int sumK(int ind, int k, vector<int> nums)
{
    if (ind == 0)
    {
        if (k % nums[ind] == 0)
        {
            return k / nums[ind];
        }
        return 1e9;
    }

    int notTake = 0 + sumK(ind - 1, k, nums);

    int take = INT_MAX;
    if (nums[ind] <= k)
    {
        take = 1 + sumK(ind, k - nums[ind], nums);
    }

    return min(notTake, take);
}

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();

    int ans = sumK(n - 1, x, num);

    if (ans >= 1e9)
    {
        return -1;
    }
    return ans;
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

        cout << minimumElements(nums, k) << endl;
    }
}

/****************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int sumK(int ind, int k, vector<int> nums, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (k % nums[ind] == 0)
        {
            return k / nums[ind];
        }
        return 1e9;
    }

    if (dp[ind][k] != -1)
    {
        return dp[ind][k];
    }

    int notTake = 0 + sumK(ind - 1, k, nums, dp);

    int take = INT_MAX;
    if (nums[ind] <= k)
    {
        take = 1 + sumK(ind, k - nums[ind], nums, dp);
    }

    return dp[ind][k] = min(notTake, take);
}

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(x + 1, -1));

    int ans = sumK(n - 1, x, num, dp);

    if (ans >= 1e9)
    {
        return -1;
    }
    return ans;
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

        cout << minimumElements(nums, k) << endl;
    }
}

/****************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    for (int target = 0; target <= x; target++)
    {
        if (target % num[0] == 0)
        {
            dp[0][target] = target / num[0];
        }
        else
        {
            dp[0][target] = 1e9;
        }
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= x; target++)
        {
            int notTake = 0 + dp[ind - 1][target];
            int take = INT_MAX;
            if (num[ind] <= target)
            {
                take = 1 + dp[ind][target - num[ind]];
            }

            dp[ind][target] = min(notTake, take);
        }
    }

    return (dp[n - 1][x] >= 1e9) ? -1 : dp[n - 1][x];
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

        cout << minimumElements(nums, k) << endl;
    }
}

/****************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();

    vector<int> prev(x + 1, 0);
    for (int target = 0; target <= x; target++)
    {
        if (target % num[0] == 0)
        {
            prev[target] = target / num[0];
        }
        else
        {
            prev[target] = 1e9;
        }
    }

    for (int ind = 1; ind < n; ind++)
    {
        vector<int> curr(x + 1, 0);

        for (int target = 0; target <= x; target++)
        {
            int notTake = 0 + prev[target];
            int take = INT_MAX;
            if (num[ind] <= target)
            {
                take = 1 + curr[target - num[ind]];
            }

            curr[target] = min(notTake, take);
        }
        prev = curr;
    }

    return (prev[x] >= 1e9) ? -1 : prev[x];
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

        cout << minimumElements(nums, k) << endl;
    }
}
