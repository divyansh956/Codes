#include <bits/stdc++.h>
using namespace std;

int maxVal(int ind, int N, vector<int> value)
{
    if (ind == 0)
    {
        return N * value[0];
    }

    int notTake = 0 + maxVal(ind - 1, N, value);

    int take = INT_MIN;
    int rodLen = ind + 1;

    if (rodLen <= N)
    {
        take = value[ind] + maxVal(ind, N - rodLen, value);
    }

    return max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
    return maxVal(n - 1, n, price);
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

        cout << cutRod(nums, n) << endl;
    }
}

/****************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int maxVal(int ind, int N, vector<int> price, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return N * price[0];
    }

    if (dp[ind][N] != -1)
    {
        return dp[ind][N];
    }

    int notTake = 0 + maxVal(ind - 1, N, price, dp);

    int take = INT_MIN;
    int rodLen = ind + 1;

    if (rodLen <= N)
    {
        take = price[ind] + maxVal(ind, N - rodLen, price, dp);
    }

    return dp[ind][N] = max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return maxVal(n - 1, n, price, dp);
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

        cout << cutRod(nums, n) << endl;
    }
}

/****************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int N = 0; N <= n; N++)
    {
        dp[0][N] = N * price[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int N = 0; N <= n; N++)
        {
            int notTake = 0 + dp[ind - 1][N];

            int take = INT_MIN;
            int rodLen = ind + 1;

            if (rodLen <= N)
            {
                take = price[ind] + dp[ind][N - rodLen];
            }

            dp[ind][N] = max(take, notTake);
        }
    }

    return dp[n - 1][n];
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

        cout << cutRod(nums, n) << endl;
    }
}

/****************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0);
    for (int N = 0; N <= n; N++)
    {
        prev[N] = N * price[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        vector<int> curr(n + 1, 0);

        for (int N = 0; N <= n; N++)
        {
            int notTake = 0 + prev[N];

            int take = INT_MIN;
            int rodLen = ind + 1;

            if (rodLen <= N)
            {
                take = price[ind] + curr[N - rodLen];
            }

            curr[N] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[n];
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

        cout << cutRod(nums, n) << endl;
    }
}
