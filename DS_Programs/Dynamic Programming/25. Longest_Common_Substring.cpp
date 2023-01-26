#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    int ans = 0;

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
                ans = max(ans, dp[ind1][ind2]);
            }
            else
            {
                dp[ind1][ind2] = 0;
            }
        }
    }

    return ans;
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

/*********************************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    int ans = 0;

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
                ans = max(ans, curr[ind2]);
            }
            else
            {
                curr[ind2] = 0;
            }
        }
        prev = curr;
    }

    return ans;
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
