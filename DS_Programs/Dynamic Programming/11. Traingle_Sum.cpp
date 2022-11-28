#include <bits/stdc++.h>
using namespace std;

int minSum(int i, int j, vector<vector<int>> &triangle, int n)
{
    if (i == n - 1)
    {
        return triangle[i][j];
    }

    int down = triangle[i][j] + minSum(i + 1, j, triangle, n);

    int diag = triangle[i][j] + minSum(i + 1, j + 1, triangle, n);

    return min(down, diag);
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    return minSum(0, 0, triangle, n);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> nums;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;

            for (int j = 0; j < i + 1; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            nums.push_back(temp);
        }

        cout << minimumPathSum(nums, n) << endl;
    }
}


/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int minSum(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{
    if (i == n - 1)
    {
        return triangle[i][j];
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int down = triangle[i][j] + minSum(i + 1, j, triangle, n, dp);

    int diag = triangle[i][j] + minSum(i + 1, j + 1, triangle, n, dp);

    return dp[i][j] = min(down, diag);
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return minSum(0, 0, triangle, n, dp);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> nums;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;

            for (int j = 0; j < i + 1; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            nums.push_back(temp);
        }

        cout << minimumPathSum(nums, n) << endl;
    }
}

/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            if (i == n - 1)
            {
                dp[i][j] = triangle[i][j];
            }
            else
            {
                int down = triangle[i][j] + dp[i + 1][j];

                int diag = triangle[i][j] + dp[i + 1][j + 1];

                dp[i][j] = min(down, diag);
            }
        }
    }

    return dp[0][0];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> nums;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;

            for (int j = 0; j < i + 1; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            nums.push_back(temp);
        }

        cout << minimumPathSum(nums, n) << endl;
    }
}

/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<int> prevRow(n, 0);
    for (int j = 0; j < n; j++)
    {
        prevRow[j] = triangle[n - 1][j];
    }

    vector<int> row(n, 0);

    for (int i = n - 2; i >= 0; i--)
    {

        for (int j = i; j >= 0; j--)
        {

            int down = triangle[i][j] + prevRow[j];

            int diag = triangle[i][j] + prevRow[j + 1];

            row[j] = min(down, diag);
        }
        prevRow = row;
    }

    return prevRow[0];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> nums;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;

            for (int j = 0; j < i + 1; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            nums.push_back(temp);
        }

        cout << minimumPathSum(nums, n) << endl;
    }
}
