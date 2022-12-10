#include <bits/stdc++.h>
using namespace std;

int maxVal(int ind, int w, vector<int> weight, vector<int> value)
{
    if (ind == 0)
    {
        if (weight[ind] <= w)
        {
            return value[ind];
        }
        return 0;
    }

    int notTake = 0 + maxVal(ind - 1, w, weight, value);

    int take = INT_MIN;
    if (weight[ind] <= w)
    {
        take = value[ind] + maxVal(ind - 1, w - weight[ind], weight, value);
    }

    return max(take, notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return maxVal(n - 1, maxWeight, weight, value);
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
        vector<int> value;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            value.push_back(x);
        }

        int w;
        cin >> w;

        cout << knapsack(nums, value, n, w) << endl;
    }
}

/****************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int maxVal(int ind, int w, vector<int> weight, vector<int> value, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (weight[ind] <= w)
        {
            return value[ind];
        }
        return 0;
    }

    if (dp[ind][w] != -1)
    {
        return dp[ind][w];
    }

    int notTake = 0 + maxVal(ind - 1, w, weight, value, dp);

    int take = INT_MIN;
    if (weight[ind] <= w)
    {
        take = value[ind] + maxVal(ind - 1, w - weight[ind], weight, value, dp);
    }

    return dp[ind][w] = max(take, notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));

    return maxVal(n - 1, maxWeight, weight, value, dp);
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
        vector<int> value;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            value.push_back(x);
        }

        int w;
        cin >> w;

        cout << knapsack(nums, value, n, w) << endl;
    }
}

/****************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        dp[0][i] = value[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int notTake = 0 + dp[ind - 1][w];

            int take = INT_MIN;
            if (weight[ind] <= w)
            {
                take = value[ind] + dp[ind - 1][w - weight[ind]];
            }

            dp[ind][w] = max(take, notTake);
        }
    }

    return dp[n - 1][maxWeight];
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
        vector<int> value;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            value.push_back(x);
        }

        int w;
        cin >> w;

        cout << knapsack(nums, value, n, w) << endl;
    }
}

/****************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0);
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        prev[i] = value[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        vector<int> curr(maxWeight + 1, 0);

        for (int w = 0; w <= maxWeight; w++)
        {
            int notTake = 0 + prev[w];

            int take = INT_MIN;
            if (weight[ind] <= w)
            {
                take = value[ind] + prev[w - weight[ind]];
            }

            curr[w] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[maxWeight];
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
        vector<int> value;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            value.push_back(x);
        }

        int w;
        cin >> w;

        cout << knapsack(nums, value, n, w) << endl;
    }
}

/****************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0);
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        prev[i] = value[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = maxWeight; w >= 0; w--)
        {
            int notTake = 0 + prev[w];

            int take = INT_MIN;
            if (weight[ind] <= w)
            {
                take = value[ind] + prev[w - weight[ind]];
            }

            prev[w] = max(take, notTake);
        }
    }

    return prev[maxWeight];
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
        vector<int> value;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            value.push_back(x);
        }

        int w;
        cin >> w;

        cout << knapsack(nums, value, n, w) << endl;
    }
}
