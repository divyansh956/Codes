#include <bits/stdc++.h>
using namespace std;

int f(int n, vector<int> &heights)
{
    if (n == 0)
    {
        return 0;
    }

    int r = INT_MAX;
    int l = f(n - 1, heights) + abs(heights[n] - heights[n - 1]);

    if (n > 1)
    {
        r = f(n - 2, heights) + abs(heights[n] - heights[n - 2]);
    }

    return min(l, r);
}

int frogJump(int n, vector<int> &heights)
{
    return f(n - 1, heights);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> heights;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            heights.push_back(x);
        }

        cout << frogJump(n, heights) << endl;
    }
}

/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int f(int n, vector<int> &heights, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int r = INT_MAX;
    int l = f(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);

    if (n > 1)
    {
        r = f(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
    }

    return dp[n] = min(l, r);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    return f(n - 1, heights, dp);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> heights;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            heights.push_back(x);
        }

        cout << frogJump(n, heights) << endl;
    }
}

/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int l = dp[i - 1] + abs(heights[i] - heights[i - 1]);

        int r = INT_MAX;

        if (i > 1)
        {
            r = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }

        dp[i] = min(l, r);
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

        vector<int> heights;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            heights.push_back(x);
        }

        cout << frogJump(n, heights) << endl;
    }
}


/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &heights)
{
    int prev1 = 0;
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int l = prev1 + abs(heights[i] - heights[i - 1]);

        int r = INT_MAX;

        if (i > 1)
        {
            r = prev2 + abs(heights[i] - heights[i - 2]);
        }

        int curr = min(l, r);
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

        vector<int> heights;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            heights.push_back(x);
        }

        cout << frogJump(n, heights) << endl;
    }
}
