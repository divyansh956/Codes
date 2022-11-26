#include <bits/stdc++.h>
using namespace std;

int f(int ind, vector<int> &nums)
{
    if (ind == 0)
    {
        return nums[0];
    }

    if (ind < 0)
    {
        return 0;
    }

    int pick = nums[ind] + f(ind - 2, nums);
    int notPick = f(ind - 1, nums);

    return max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    return f(nums.size() - 1, nums);
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

        cout << maximumNonAdjacentSum(nums) << endl;
    }
}

/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int f(int ind, vector<int> &nums, vector<int> &dp)
{
    if (ind == 0)
    {
        return nums[ind];
    }

    if (ind < 0)
    {
        return 0;
    }

    if (dp[ind] != -1)
    {
        return dp[ind];
    }

    int pick = nums[ind] + f(ind - 2, nums, dp);
    int notPick = f(ind - 1, nums, dp);

    dp[ind] = max(pick, notPick);

    return dp[ind];
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int sz = nums.size();
    vector<int> dp(sz, -1);

    return f(sz - 1, nums, dp);
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

        cout << maximumNonAdjacentSum(nums) << endl;
    }
}

/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n, -1);
    dp[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];

        if (i > 1)
        {
            pick += dp[i - 2];
        }

        int notPick = dp[i - 1];

        dp[i] = max(pick, notPick);
    }
    
    return dp[n - 1];
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

        cout << maximumNonAdjacentSum(nums) << endl;
    }
}

/*****************************************************************************************************************/


 #include <bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();

    int prev1 = nums[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];

        if (i > 1)
        {
            pick += prev2;
        }

        int notPick = prev1;

        int curr = max(pick, notPick);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
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

        cout << maximumNonAdjacentSum(nums) << endl;
    }
}
