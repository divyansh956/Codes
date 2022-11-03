#include <bits/stdc++.h>
using namespace std;

int jumpSearch(int nums[], int n, int key)
{
    int st = 0;
    int en = sqrt(n);

    while (nums[en] <= key && en < n)
    {
        st = en;
        en += sqrt(n);
        if (en > n - 1)
        {
            en = n;
        }
    }

    for (int i = st; i < en; i++)
    {
        if (nums[i] == key)
        {
            return i;
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

    cout << jumpSearch(nums, n, key) << endl;

    return 0;
}
