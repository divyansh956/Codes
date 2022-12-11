#include <bits/stdc++.h>
using namespace std;

int findways(int ind, int k, vector<int> arr)
{
    if (ind == 0)
    {
        return (abs(k) == abs(arr[ind])) ? 1 : 0;
    }

    int pos = findways(ind - 1, k - arr[ind], arr);

    int neg = findways(ind - 1, k + arr[ind], arr);

    return pos + neg;
}

int targetSum(int n, int target, vector<int> &arr)
{
    return findways(n - 1, target, arr);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        cout << targetSum(n, k, nums) << endl;
    }
}

/****************************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int findWays(vector<int> &num, int tar)
{
    int n = num.size();

    vector<int> prevRow(tar + 1, 0);

    for (int i = 0; i < n; i++)
    {
        prevRow[0] = 1;
    }

    if (num[0] <= tar)
    {
        prevRow[num[0]] = 1;
    }

    if (num[0] == 0)
    {
        prevRow[0] = 2;
    }
    else
    {
        prevRow[0] = 1;
    }

    for (int ind = 1; ind < n; ind++)
    {
        vector<int> curr(tar + 1, 0);

        for (int k = 0; k <= tar; k++)
        {
            int pick = 0;
            if (k >= num[ind])
            {
                pick = prevRow[k - num[ind]];
            }

            int notPick = prevRow[k];

            curr[k] = (pick + notPick) % mod;
        }
        prevRow = curr;
    }
    return prevRow[tar];
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int total = 0;
    for (auto x : arr)
    {
        total += x;
    }

    if (total - d < 0 || (total - d) % 2 != 0)
    {
        return 0;
    }

    return findWays(arr, (total - d) / 2);
}

int targetSum(int n, int target, vector<int> &arr)
{
    return countPartitions(n, target, arr);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        cout << targetSum(n, k, nums) << endl;
    }
}
