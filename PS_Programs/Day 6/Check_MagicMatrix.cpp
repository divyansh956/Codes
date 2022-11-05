#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int nums[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> nums[i][j];
        }
    }

    unordered_map<int, int> mp;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += nums[i][j];
        }
        mp[sum]++;
        sum = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += nums[j][i];
        }
        mp[sum]++;
        sum = 0;
    }

    int sum1 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                sum += nums[i][j];
            }
            if (i + j == n - 1)
            {
                sum1 += nums[i][j];
            }
        }
    }
    mp[sum]++;
    mp[sum1]++;

    if (mp.size() == 1)
    {
        cout << "Magic Matrix" << endl;
    }
    else
    {
        cout << "Not Magic Matrix" << endl;
    }
}
