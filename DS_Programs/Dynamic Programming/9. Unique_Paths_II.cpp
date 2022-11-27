#include <bits/stdc++.h>
using namespace std;

int mod = (int)(1e9 + 7);

int paths(int r, int c, vector<vector<int>> &mat)
{
    if (r >= 0 && c >= 0 && mat[r][c] == -1)
    {
        return 0;
    }

    if (r == 0 && c == 0)
    {
        return 1;
    }

    if (r < 0 || c < 0)
    {
        return 0;
    }

    int up = paths(r - 1, c, mat);

    int left = paths(r, c - 1, mat);

    return (up + left) % mod;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    return paths(n - 1, m - 1, mat);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;

        vector<vector<int>> nums;
        for (int i = 0; i < r; i++)
        {
            vector<int> temp;

            for (int j = 0; j < c; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            nums.push_back(temp);
        }

        cout << mazeObstacles(r, c, nums) << endl;
    }
}

/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int mod = (int)(1e9 + 7);

int paths(int r, int c, vector<vector<int>> &mat, vector<vector<int>> dp)
{
    if (r >= 0 && c >= 0 && mat[r][c] == -1)
    {
        return 0;
    }

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

    int up = paths(r - 1, c, mat, dp);

    int left = paths(r, c - 1, mat, dp);

    return dp[r][c] = (up + left) % mod;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));

    return paths(n - 1, m - 1, mat, dp);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;

        vector<vector<int>> nums;
        for (int i = 0; i < r; i++)
        {
            vector<int> temp;

            for (int j = 0; j < c; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            nums.push_back(temp);
        }

        cout << mazeObstacles(r, c, nums) << endl;
    }
}

/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int mod = (int)(1e9 + 7);

int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == -1)
            {
                dp[i][j] == 0;
            }
            else if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
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

                dp[i][j] = (up + left) % mod;
            }
        }
    }
    return dp[n - 1][m - 1];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;

        vector<vector<int>> nums;
        for (int i = 0; i < r; i++)
        {
            vector<int> temp;

            for (int j = 0; j < c; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            nums.push_back(temp);
        }

        cout << mazeObstacles(r, c, nums) << endl;
    }
}

/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int mod = (int)(1e9 + 7);

int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    vector<int> prevRow(m, 0);

    for (int i = 0; i < n; i++)
    {
        vector<int> row(m, 0);

        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == -1)
            {
                row[j] = 0;
            }
            else if (i == 0 && j == 0)
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

                row[j] = (up + left) % mod;
            }
        }
        prevRow = row;
    }

    return prevRow[m - 1];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;

        vector<vector<int>> nums;
        for (int i = 0; i < r; i++)
        {
            vector<int> temp;

            for (int j = 0; j < c; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            nums.push_back(temp);
        }

        cout << mazeObstacles(r, c, nums) << endl;
    }
}
