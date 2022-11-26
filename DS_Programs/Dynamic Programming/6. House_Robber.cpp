#include <bits/stdc++.h>
using namespace std;

long long int f(int ind, vector<int> &nums)
{
    if (ind == 0)
    {
        return nums[0];
    }

    if (ind < 0)
    {
        return 0;
    }

    long long int pick = nums[ind] + f(ind - 2, nums);
    long long int notPick = f(ind - 1, nums);

    return max(pick, notPick);
}

long long int houseRobber(vector<int> &valueInHouse)
{
    vector<int> temp1, temp2;
    int n = valueInHouse.size();

    if (n == 1)
    {
        return valueInHouse[0];
    }

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            temp1.push_back(valueInHouse[i]);
        }
        if (i != n - 1)
        {
            temp2.push_back(valueInHouse[i]);
        }
    }

    return max(f(temp1.size() - 1, temp1), f(temp2.size() - 1, temp2));
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

        cout << houseRobber(nums) << endl;
    }
}

/*****************************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

long long int f(int ind, vector<int> &nums, vector<long long int> &dp)
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

    long long int pick = nums[ind] + f(ind - 2, nums, dp);
    long long int notPick = f(ind - 1, nums, dp);

    dp[ind] = max(pick, notPick);

    return dp[ind];
}

long long int houseRobber(vector<int> &valueInHouse)
{
    vector<int> temp1, temp2;
    int n = valueInHouse.size();

    if (n == 1)
    {
        return valueInHouse[0];
    }

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            temp1.push_back(valueInHouse[i]);
        }
        if (i != n - 1)
        {
            temp2.push_back(valueInHouse[i]);
        }
    }

    vector<long long int> dp1(n - 1, -1);
    vector<long long int> dp2(n - 1, -1);

    return max(f(temp1.size() - 1, temp1, dp1), f(temp2.size() - 1, temp2, dp2));
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

        cout << houseRobber(nums) << endl;
    }
}

/*****************************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

long long int Robber(vector<int> &nums)
{
    int n = nums.size();

    vector<long long int> dp(n, -1);
    dp[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        long long int pick = nums[i];

        if (i > 1)
        {
            pick += dp[i - 2];
        }

        long long int notPick = dp[i - 1];

        dp[i] = max(pick, notPick);
    }

    return dp[n - 1];
}

long long int houseRobber(vector<int> &valueInHouse)
{
    vector<int> temp1, temp2;
    int n = valueInHouse.size();

    if (n == 1)
    {
        return valueInHouse[0];
    }

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            temp1.push_back(valueInHouse[i]);
        }
        if (i != n - 1)
        {
            temp2.push_back(valueInHouse[i]);
        }
    }

    return max(Robber(temp1), Robber(temp2));
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

        cout << houseRobber(nums) << endl;
    }
}

/*****************************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

long long int Robber(vector<int> &nums)
{
    int n = nums.size();

    long long int prev1 = nums[0];
    long long int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        long long int pick = nums[i];

        if (i > 1)
        {
            pick += prev2;
        }

        long long int notPick = prev1;

        long long int curr = max(pick, notPick);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

long long int houseRobber(vector<int> &valueInHouse)
{
    vector<int> temp1, temp2;
    int n = valueInHouse.size();

    if (n == 1)
    {
        return valueInHouse[0];
    }

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            temp1.push_back(valueInHouse[i]);
        }
        if (i != n - 1)
        {
            temp2.push_back(valueInHouse[i]);
        }
    }

    return max(Robber(temp1), Robber(temp2));
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

        cout << houseRobber(nums) << endl;
    }
}
