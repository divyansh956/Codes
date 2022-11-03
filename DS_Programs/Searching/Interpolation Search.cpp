#include <bits/stdc++.h>
using namespace std;

int interpolationSearch(int nums[], int n, int key)
{
    int st = 0, en = n - 1;

    while (st <= en && key <= nums[en] && key >= nums[st])
    {
        float fraction = (key - nums[st]) / (nums[en] -nums[st]);
        int idxRange = en - st;
        int est = st + (fraction * idxRange);
        
        if (nums[est] == key)
        {
            return est;
        }
        if (nums[est] < key)
        {
            st = est + 1;
        }
        else
        {
            en = est - 1;
        }
    }
    return -1;
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

    int key;
    cin >> key;

    cout << interpolationSearch(nums, n, key) << endl;

    return 0;
}
