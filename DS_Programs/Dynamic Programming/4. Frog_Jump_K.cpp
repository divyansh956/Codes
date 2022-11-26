#include <bits/stdc++.h>
using namespace std;

int f(int n, vector<int> &heights, int k)
{
    if (n == 0)
    {
        return 0;
    }

    int ans = INT_MAX;

    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            int res = f(n - i, heights, k) + abs(heights[n] - heights[n - i]);
            ans = min(ans, res);
        }
    }
    return ans;
}

int frogJump(int n, vector<int> &heights, int k)
{
    return f(n - 1, heights, k);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> heights;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            heights.push_back(x);
        }

        cout << frogJump(n, heights, k) << endl;
    }
}

/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int f(int n, vector<int> &heights, int k, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != INT_MAX)
    {
        return dp[n];
    }

    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            int res = f(n - i, heights, k, dp) + abs(heights[n] - heights[n - i]);
            dp[n] = min(dp[n], res);
        }
    }
    return dp[n];
}

int frogJump(int n, vector<int> &heights, int k)
{
    vector<int> dp(n, INT_MAX);
    return f(n - 1, heights, k, dp);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> heights;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            heights.push_back(x);
        }

        cout << frogJump(n, heights, k) << endl;
    }
}


/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &heights, int k)
{
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int res = dp[i - j] + abs(heights[i] - heights[i - j]);
                dp[i] = min(dp[i], res);
            }
        }
    }
    return dp[n - 1];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> heights;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            heights.push_back(x);
        }

        cout << frogJump(n, heights, k) << endl;
    }
}
