#include <bits/stdc++.h>
using namespace std;

int solve(int ind1, int ind2, string &s1, string &s2)
{
    if (ind1 < 0 || ind2 < 0)
    {
        return 0;
    }

    if (s1[ind1] == s2[ind2])
    {
        return 1 + solve(ind1 - 1, ind2 - 1, s1, s2);
    }

    return max(solve(ind1 - 1, ind2, s1, s2), solve(ind1, ind2 - 1, s1, s2));
}

int lcs(string s, string t)
{
    int n1 = s.length();
    int n2 = t.length();

    return n1 + n2 - 2 * solve(n1 - 1, n2 - 1, s, t);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        cout << lcs(s1, s2) << endl;
    }
}

/****************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int solve(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (ind1 == 0 || ind2 == 0)
    {
        return 0;
    }

    if (dp[ind1][ind2] != -1)
    {
        return dp[ind1][ind2];
    }

    if (s1[ind1 - 1] == s2[ind2 - 1])
    {
        return dp[ind1][ind2] = 1 + solve(ind1 - 1, ind2 - 1, s1, s2, dp);
    }

    return dp[ind1][ind2] = max(solve(ind1 - 1, ind2, s1, s2, dp), solve(ind1, ind2 - 1, s1, s2, dp));
}

int lcs(string s, string t)
{
    int n1 = s.length();
    int n2 = t.length();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

    return n1 + n2 - 2 * solve(n1, n2, s, t, dp);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        cout << lcs(s1, s2) << endl;
    }
}

/****************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
    for (int ind1 = 0; ind1 <= n1; ind1++)
    {
        dp[ind1][0] = 0;
    }
    for (int ind2 = 0; ind2 <= n2; ind2++)
    {
        dp[0][ind2] = 0;
    }

    for (int ind1 = 1; ind1 <= n1; ind1++)
    {
        for (int ind2 = 1; ind2 <= n2; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
            {
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            }
            else
            {
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }
    }

    return n1 + n2 - 2 * dp[n1][n2];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        cout << lcs(s1, s2) << endl;
    }
}

/****************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();

    vector<int> prev(n2 + 1, 0);
    for (int ind2 = 0; ind2 <= n2; ind2++)
    {
        prev[ind2] = 0;
    }

    for (int ind1 = 1; ind1 <= n1; ind1++)
    {
        vector<int> curr(n2 + 1, 0);

        for (int ind2 = 1; ind2 <= n2; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
            {
                curr[ind2] = 1 + prev[ind2 - 1];
            }
            else
            {
                curr[ind2] = max(prev[ind2], curr[ind2 - 1]);
            }
        }
        prev = curr;
    }

    return n1 + n2 - 2 * prev[n2];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        cout << lcs(s1, s2) << endl;
    }
}
