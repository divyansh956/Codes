#include <bits/stdc++.h>
using namespace std;

int maxSum(int r, int c, vector<vector<int>> &matrix)
{
    if (c >= matrix[0].size() || c < 0)
    {
        return -1e9;
    }

    if (r == 0)
    {
        return matrix[r][c];
    }

    int up = matrix[r][c] + maxSum(r - 1, c, matrix);

    int up_left = matrix[r][c] + maxSum(r - 1, c - 1, matrix);

    int up_right = matrix[r][c] + maxSum(r - 1, c + 1, matrix);

    return max(up, max(up_left, up_right));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();

    int mx = INT_MIN;

    for (int j = 0; j < c; j++)
    {
        mx = max(mx, maxSum(r - 1, j, matrix));
    }

    return mx;
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

        cout << getMaxPathSum(nums) << endl;
    }
}


/******************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int maxSum(int r, int c, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (c >= matrix[0].size() || c < 0)
    {
        return -1e9;
    }

    if (r == 0)
    {
        return matrix[r][c];
    }

    if (dp[r][c] != -1)
    {
        return dp[r][c];
    }

    int up = matrix[r][c] + maxSum(r - 1, c, matrix, dp);

    int up_left = matrix[r][c] + maxSum(r - 1, c - 1, matrix, dp);

    int up_right = matrix[r][c] + maxSum(r - 1, c + 1, matrix, dp);

    return dp[r][c] = max(up, max(up_left, up_right));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();

    vector<vector<int>> dp(r, vector<int>(c, -1));

    int mx = INT_MIN;

    for (int j = 0; j < c; j++)
    {
        mx = max(mx, maxSum(r - 1, j, matrix, dp));
    }

    return mx;
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

        cout << getMaxPathSum(nums) << endl;
    }
}

/******************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();

    vector<vector<int>> dp(r, vector<int>(c, 0));
    for (int j = 0; j < c; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    int mx = INT_MIN;

    for (int i = 1; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int up = matrix[i][j] + dp[i - 1][j];

            int up_left = matrix[i][j];

            if (j > 0)
            {
                up_left += dp[i - 1][j - 1];
            }
            else
            {
                up_left += -1e9;
            }

            int up_right = matrix[i][j];

            if (j < c - 1)
            {
                up_right += dp[i - 1][j + 1];
            }
            else
            {
                up_right += -1e9;
            }

            dp[i][j] = max(up, max(up_left, up_right));
        }
    }

    for (int j = 0; j < c; j++)
    {
        mx = max(mx, dp[r - 1][j]);
    }

    return mx;
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

        cout << getMaxPathSum(nums) << endl;
    }
}

/******************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();

    vector<int> prevRow(c, 0);
    for (int j = 0; j < c; j++)
    {
        prevRow[j] = matrix[0][j];
    }

    int mx = INT_MIN;

    for (int i = 1; i < r; i++)
    {
        vector<int> curr(c, 0);

        for (int j = 0; j < c; j++)
        {
            int up = matrix[i][j] + prevRow[j];

            int up_left = matrix[i][j];

            if (j > 0)
            {
                up_left += prevRow[j - 1];
            }
            else
            {
                up_left += -1e9;
            }

            int up_right = matrix[i][j];

            if (j < c - 1)
            {
                up_right += prevRow[j + 1];
            }
            else
            {
                up_right += -1e9;
            }

            curr[j] = max(up, max(up_left, up_right));
        }
        prevRow = curr;
    }

    for (int j = 0; j < c; j++)
    {
        mx = max(mx, prevRow[j]);
    }

    return mx;
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

        cout << getMaxPathSum(nums) << endl;
    }
}
