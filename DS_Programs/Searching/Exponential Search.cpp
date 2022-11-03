#include <bits/stdc++.h>
using namespace std;

int binarySearch(int nums[], int st, int en, int key)
{
    if (st <= en)
    {
        int mid = (st + en) / 2;
        if (nums[mid] == key)
        {
            return mid;
        }
        if (nums[mid] > key)
        {
            return binarySearch(nums, st, mid - 1, key);
        }
        return binarySearch(nums, mid + 1, en, key);
    }
    return -1;
}

int exponentialSearch(int nums[], int n, int key)
{
    int st = 0, en = n;
    if (st >= en)
    {
        return -1;
    }
    
    int i = 1;
    while (i < (en - st))
    {
        if (nums[i] < key)
        {
            i *= 2;
        }
        else
        {
            break;
        }
    }
    return binarySearch(nums, i / 2, i, key);
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

    cout << exponentialSearch(nums, n, key) << endl;

}
