#include <bits/stdc++.h>
using namespace std;

int minSum(int r, int c, vector<vector<int>> &grid)
{
    if (r == 0 && c == 0)
    {
        return grid[r][c];
    }

    if (r < 0 || c < 0)
    {
        return 1e9;
    }

    int up = grid[r][c] + minSum(r - 1, c, grid);

    int left = grid[r][c] + minSum(r, c - 1, grid);

    return min(up, left);
}

int minSumPath(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();

    return minSum(r - 1, c - 1, grid);
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

        cout << minSumPath(nums) << endl;
    }
}


/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int minSum(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (r == 0 && c == 0)
    {
        return grid[r][c];
    }

    if (r < 0 || c < 0)
    {
        return 1e9;
    }

    if (dp[r][c] != -1)
    {
        return dp[r][c];
    }

    int up = grid[r][c] + minSum(r - 1, c, grid, dp);

    int left = grid[r][c] + minSum(r, c - 1, grid, dp);

    return dp[r][c] = min(up, left);
}

int minSumPath(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();

    vector<vector<int>> dp(r, vector<int>(c, -1));

    return minSum(r - 1, c - 1, grid, dp);
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

        cout << minSumPath(nums) << endl;
    }
}

/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int minSumPath(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();

    vector<vector<int>> dp(r, vector<int>(c));
    dp[0][0] = grid[0][0];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!(i == 0 && j == 0))
            {
                int up = grid[i][j], left = grid[i][j];

                if (i > 0)
                {
                    up += dp[i - 1][j];
                }
                else
                {
                    up += 1e9;
                }

                if (j > 0)
                {
                    left += dp[i][j - 1];
                }
                else
                {
                    left += 1e9;
                }

                dp[i][j] = min(up, left);
            }
        }
    }

    return dp[r - 1][c - 1];
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

        cout << minSumPath(nums) << endl;
    }
}

/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int minSumPath(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();

    vector<int> prevRow(c);

    for (int i = 0; i < r; i++)
    {
        vector<int> row(c);

        for (int j = 0; j < c; j++)
        {
            if (i == 0 && j == 0)
            {
                row[j] = grid[i][j];
            }

            else
            {
                int up = grid[i][j], left = grid[i][j];

                if (i > 0)
                {
                    up += prevRow[j];
                }
                else
                {
                    up += 1e9;
                }

                if (j > 0)
                {
                    left += row[j - 1];
                }
                else
                {
                    left += 1e9;
                }

                row[j] = min(up, left);
            }
        }
        prevRow = row;
    }

    return prevRow[c - 1];
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

        cout << minSumPath(nums) << endl;
    }
}
