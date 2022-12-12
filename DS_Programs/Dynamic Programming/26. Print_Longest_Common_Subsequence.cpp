#include <bits/stdc++.h>
using namespace std;

void lcs(string s1, string s2)
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

    string ans = "";

    int ind1 = n1, ind2 = n2;
    while (ind1 > 0 && ind2 > 0)
    {
        if (s1[ind1 - 1] == s2[ind2 - 1])
        {
            ans = s1[ind1 - 1] + ans;
            ind1--;
            ind2--;
        }
        else if (dp[ind1 - 1][ind2] > dp[ind1][ind2 - 1])
        {
            ind1--;
        }
        else
        {
            ind2--;
        }
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        lcs(s1, s2);
    }
}

/****************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

void lcs(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();

    vector<int> prev(n2 + 1, 0);
    vector<int> curr(n2 + 1, 0);

    for (int ind2 = 0; ind2 <= n2; ind2++)
    {
        prev[ind2] = 0;
    }

    for (int ind1 = 1; ind1 <= n1; ind1++)
    {
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

    string ans = "";

    int i = n1, j = n2;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans = s1[i - 1] + ans;
            i--;
            j--;
        }
        else if (prev[j] > curr[j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        lcs(s1, s2);
    }
}
