#include <bits/stdc++.h>
using namespace std;

void subsequence(int nums[], int i, int n, vector<int> &ans)
{
    if (i == n)
    {
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    ans.push_back(nums[i]);
    subsequence(nums, i + 1, n, ans);
    
    ans.pop_back();
    subsequence(nums, i + 1, n, ans);
}

int main()
{
    int n;
    cin >> n;

    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> ans;

    subsequence(nums, 0, n, ans);
}
