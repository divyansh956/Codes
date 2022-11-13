#include <bits/stdc++.h>
using namespace std;

bool subsequence(int nums[], int i, int n, vector<int> &ans, int sum, int k)
{
    if (i == n)
    {
        if (sum == k)
        {
            for (auto x : ans)
            {
                cout << x << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }

    ans.push_back(nums[i]);
    sum += nums[i];

    if (subsequence(nums, i + 1, n, ans, sum, k) == true)
    {
        return true;
    }

    ans.pop_back();
    sum -= nums[i];

    if (subsequence(nums, i + 1, n, ans, sum, k) == true)
    {
        return true;
    }
    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> ans;

    subsequence(nums, 0, n, ans, 0, k);
}
