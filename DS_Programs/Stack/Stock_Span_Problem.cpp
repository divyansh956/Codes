#include <bits/stdc++.h>
using namespace std;

vector<int> stockspan(vector<int> prices)
{
    vector<int> ans;

    stack<pair<int, int>> s;
    for (auto price : prices)
    {
        int days = 1;
        while (!s.empty() && s.top().first <= price)
        {
            days += s.top().second;
            s.pop();
        }
        s.push({price, days});
        ans.push_back(days);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> res = stockspan(nums);

    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << endl;
}
