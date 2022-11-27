#include <bits/stdc++.h>
using namespace std;

int paths(int r, int c)
{
    if (r == 0 && c == 0)
    {
        return 1;
    }

    if (r < 0 || c < 0)
    {
        return 0;
    }

    int up = paths(r - 1, c);

    int left = paths(r, c - 1);

    return up + left;
}

int uniquePaths(int m, int n)
{
    return paths(m - 1, n - 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;

        cout << uniquePaths(r, c) << endl;
    }
}

/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int paths(int r, int c, vector<vector<int>> &dp)
{
    if (r == 0 && c == 0)
    {
        return 1;
    }

    if (r < 0 || c < 0)
    {
        return 0;
    }

    if (dp[r][c] != -1)
    {
        return dp[r][c];
    }

    int up = paths(r - 1, c, dp);

    int left = paths(r, c - 1, dp);

    return dp[r][c] = up + left;
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return paths(m - 1, n - 1, dp);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;

        cout << uniquePaths(r, c) << endl;
    }
}

/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[0][0] = 1;
            }
            else
            {
                int up = 0, left = 0;

                if (i > 0)
                {
                    up = dp[i - 1][j];
                }

                if (j > 0)
                {
                    left = dp[i][j - 1];
                }

                dp[i][j] = up + left;
            }
        }
    }

    return dp[m - 1][n - 1];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;

        cout << uniquePaths(r, c) << endl;
    }
}

/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n)
{
    vector<int> prevRow(n, 0);

    for (int i = 0; i < m; i++)
    {
        vector<int> row(n, 0);

        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                row[0] = 1;
            }
            else
            {
                int up = 0, left = 0;

                if (i > 0)
                {
                    up = prevRow[j];
                }

                if (j > 0)
                {
                    left = row[j - 1];
                }

                row[j] = up + left;
            }
        }
        prevRow = row;
    }

    return prevRow[n - 1];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;

        cout << uniquePaths(r, c) << endl;
    }
}
