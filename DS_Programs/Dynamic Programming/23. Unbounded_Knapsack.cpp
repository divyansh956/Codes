#include <bits/stdc++.h>
using namespace std;

int maxVal(int ind, int w, vector<int> weight, vector<int> value)
{
    if (ind == 0)
    {
        if (weight[ind] > w)
        {
            return 0;
        }
        return w / weight[ind] * value[ind];
    }

    int notTake = 0 + maxVal(ind - 1, w, weight, value);

    int take = INT_MIN;
    if (weight[ind] <= w)
    {
        take = value[ind] + maxVal(ind, w - weight[ind], weight, value);
    }

    return max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    return maxVal(n - 1, w, weight, profit);
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

        cout << unboundedKnapsack(n, w, value, nums) << endl;
    }
}

/****************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int maxVal(int ind, int w, vector<int> weight, vector<int> value, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (weight[ind] > w)
        {
            return 0;
        }

        return w / weight[ind] * value[ind];
    }

    if (dp[ind][w] != -1)
    {
        return dp[ind][w];
    }

    int notTake = 0 + maxVal(ind - 1, w, weight, value, dp);

    int take = INT_MIN;
    if (weight[ind] <= w)
    {
        take = value[ind] + maxVal(ind, w - weight[ind], weight, value, dp);
    }

    return dp[ind][w] = max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));

    return maxVal(n - 1, w, weight, profit, dp);
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

        cout << unboundedKnapsack(n, w, value, nums) << endl;
    }
}

/****************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    for (int k = 0; k <= w; k++)
    {
        dp[0][k] = k / weight[0] * profit[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int k = 0; k <= w; k++)
        {
            int notTake = 0 + dp[ind - 1][k];

            int take = INT_MIN;
            if (weight[ind] <= k)
            {
                take = profit[ind] + dp[ind][k - weight[ind]];
            }

            dp[ind][k] = max(take, notTake);
        }
    }

    return dp[n - 1][w];
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

        cout << unboundedKnapsack(n, w, value, nums) << endl;
    }
}

/****************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w + 1, 0);
    for (int k = 0; k <= w; k++)
    {
        prev[k] = k / weight[0] * profit[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        vector<int> curr(w + 1, 0);

        for (int k = 0; k <= w; k++)
        {
            int notTake = 0 + prev[k];

            int take = INT_MIN;
            if (weight[ind] <= k)
            {
                take = profit[ind] + curr[k - weight[ind]];
            }

            curr[k] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[w];
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

        cout << unboundedKnapsack(n, w, value, nums) << endl;
    }
}
