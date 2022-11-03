#include <bits/stdc++.h>
using namespace std;

int ternaryseach(int nums[], int n, int key)
{
    int st = 0;
    int en = n - 1;

    while (st <= en)
    {
        int mid1 = (st + en) / 3;
        int mid2 = n-mid1;

        if (nums[mid1] == key)
        {
            return mid1;
        }
        if (nums[mid2] == key)
        {
            return mid2;
        }

        if (key < nums[mid1])
        {
            en = mid1 - 1;
        }
        else if (key > nums[mid2])
        {
            st = mid2 + 1;
        }
        else
        {
            st = mid1 + 1;
            en = mid2 - 1;
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

    cout << ternaryseach(nums, n, key) << endl;

    return 0;
}
