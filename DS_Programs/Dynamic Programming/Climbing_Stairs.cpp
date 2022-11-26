class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;

        int l = climbStairs(n - 1);
        int r = climbStairs(n - 2);

        return l + r;
    }
};

/*****************************************************************************************************************/

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1 << endl;
    }

    int prev2 = 1;
    int prev1 = 2;

    for (int i = 2; i < n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    cout << prev1 << endl;
}
