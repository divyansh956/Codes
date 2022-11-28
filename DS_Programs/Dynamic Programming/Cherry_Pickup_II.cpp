#include <bits/stdc++.h>
using namespace std;

int maxSum(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid)
{
    if (j1 < 0 || j1 > c - 1 || j2 < 0 || j2 > c - 1)
    {
        return -1e9;
    }

    if (i == r - 1)
    {
        if (j1 == j2)
        {
            return grid[i][j1];
        }
        return grid[i][j1] + grid[i][j2];
    }

    int mx = INT_MIN;

    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int val = 0;

            if (j1 == j2)
            {
                val = grid[i][j1];
            }
            else
            {
                val = grid[i][j1] + grid[i][j2];
            }

            val += maxSum(i + 1, j1 + dj1, j2 + dj2, r, c, grid);
            mx = max(mx, val);
        }
    }
    
    return mx;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    return maxSum(0, 0, c - 1, r, c, grid);
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

        cout << maximumChocolates(r, c, nums) << endl;
    }
}

/******************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int maxSum(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j1 > c - 1 || j2 < 0 || j2 > c - 1)
    {
        return -1e9;
    }

    if (i == r - 1)
    {
        if (j1 == j2)
        {
            return grid[i][j1];
        }
        return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
    {
        return dp[i][j1][j2];
    }

    int mx = INT_MIN;

    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int val = 0;

            if (j1 == j2)
            {
                val = grid[i][j1];
            }
            else
            {
                val = grid[i][j1] + grid[i][j2];
            }

            val += maxSum(i + 1, j1 + dj1, j2 + dj2, r, c, grid, dp);
            mx = max(mx, val);
        }
    }

    return dp[i][j1][j2] = mx;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

    return maxSum(0, 0, c - 1, r, c, grid, dp);
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

        cout << maximumChocolates(r, c, nums) << endl;
    }
}

/******************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));

    for (int j1 = 0; j1 < c; j1++)
    {
        for (int j2 = 0; j2 < c; j2++)
        {
            if (j1 == j2)
            {
                dp[r - 1][j1][j2] = grid[r - 1][j1];
            }
            else
            {
                dp[r - 1][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
            }
        }
    }

    for (int i = r - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                int mx = INT_MIN;

                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    int val = 0;

                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int val = 0;

                        if (j1 == j2)
                        {
                            val = grid[i][j1];
                        }
                        else
                        {
                            val = grid[i][j1] + grid[i][j2];
                        }

                        if (j1 + dj1 >= 0 && j1 + dj1 < c && j2 + dj2 > 0 && j2 + dj2 < c)
                        {
                            val += dp[i + 1][j1 + dj1][j2 + dj2];
                        }
                        else
                        {
                            val += -1e9;
                        }
                        mx = max(mx, val);
                    }
                }

                dp[i][j1][j2] = mx;
            }
        }
    }

    return dp[0][0][c - 1];
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

        cout << maximumChocolates(r, c, nums) << endl;
    }
}

/******************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<int>> front(c, vector<int>(c, 0));

    for (int j1 = 0; j1 < c; j1++)
    {
        for (int j2 = 0; j2 < c; j2++)
        {
            if (j1 == j2)
            {
                front[j1][j2] = grid[r - 1][j1];
            }
            else
            {
                front[j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
            }
        }
    }

    for (int i = r - 2; i >= 0; i--)
    {
        vector<vector<int>> curr(c, vector<int>(c, 0));
        
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                int mx = INT_MIN;

                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    int val = 0;

                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int val = 0;

                        if (j1 == j2)
                        {
                            val = grid[i][j1];
                        }
                        else
                        {
                            val = grid[i][j1] + grid[i][j2];
                        }

                        if (j1 + dj1 >= 0 && j1 + dj1 < c && j2 + dj2 > 0 && j2 + dj2 < c)
                        {
                            val += front[j1 + dj1][j2 + dj2];
                        }
                        else
                        {
                            val += -1e9;
                        }
                        mx = max(mx, val);
                    }
                }
                curr[j1][j2] = mx;
            }
        }
        front = curr;
    }

    return front[0][c - 1];
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

        cout << maximumChocolates(r, c, nums) << endl;
    }
}
