#include <bits/stdc++.h>
using namespace std;

long long int catalon(int n, vector<long long int> &dp)
{
    if (n == 0)
    {
        return 1;
    }

    if (n == 1)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (catalon(n - 1 - i, dp) * catalon(i, dp));
    }
    return dp[n] = sum;
}

int main()
{
    int n;
    cin >> n;

    vector<long long int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        long long int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += (dp[i - 1 - j] * dp[j]);
        }
        dp[i] = sum;
    }

    cout << dp[n] << endl;
}
