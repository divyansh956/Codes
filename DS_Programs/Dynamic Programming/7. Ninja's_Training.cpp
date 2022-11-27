#include <bits/stdc++.h>
using namespace std;

int f(int day, int last, vector<vector<int>> &points)
{
    if (day == 0)
    {
        int mx = INT_MIN;

        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                mx = max(mx, points[0][i]);
            }
        }
        return mx;
    }

    int mx = INT_MIN;

    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int point = points[day][i] + f(day - 1, i, points);
            mx = max(mx, point);
        }
    }
    return mx;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return f(n - 1, 3, points);
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
            int x, y, z;
            cin >> x >> y >> z;
            nums.push_back({x, y, z});
        }

        cout << ninjaTraining(n, nums) << endl;
    }
}


/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int mx = INT_MIN;

        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                mx = max(mx, points[0][i]);
            }
        }
        return mx;
    }

    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }

    int mx = INT_MIN;

    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int point = points[day][i] + f(day - 1, i, points, dp);
            mx = max(mx, point);
        }
    }
    return dp[day][last] = mx;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));

    return f(n - 1, 3, points, dp);
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
            int x, y, z;
            cin >> x >> y >> z;
            nums.push_back({x, y, z});
        }

        cout << ninjaTraining(n, nums) << endl;
    }
}

/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int mx = INT_MIN;

        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                mx = max(mx, points[0][i]);
            }
        }
        return mx;
    }

    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }

    int mx = INT_MIN;

    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int point = points[day][i] + f(day - 1, i, points, dp);
            mx = max(mx, point);
        }
    }
    return dp[day][last] = mx;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;

            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[n - 1][3];
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
            int x, y, z;
            cin >> x >> y >> z;
            nums.push_back({x, y, z});
        }

        cout << ninjaTraining(n, nums) << endl;
    }
}

/*****************************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int mx = INT_MIN;

        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                mx = max(mx, points[0][i]);
            }
        }
        return mx;
    }

    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }

    int mx = INT_MIN;

    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int point = points[day][i] + f(day - 1, i, points, dp);
            mx = max(mx, point);
        }
    }
    return dp[day][last] = mx;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, -1);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, -1);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;

            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + prev[task];
                    temp[last] = max(temp[last], point);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
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
            int x, y, z;
            cin >> x >> y >> z;
            nums.push_back({x, y, z});
        }

        cout << ninjaTraining(n, nums) << endl;
    }
}
