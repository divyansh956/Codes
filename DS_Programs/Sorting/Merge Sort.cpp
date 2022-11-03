#include <bits/stdc++.h>
using namespace std;

void merge(int nums[], int st, int mid, int en)
{
    int i = st, j = mid + 1, k = st;
    int ans[en + 1];

    while (i <= mid && j <= en)
    {
        if (nums[i] < nums[j])
        {
            ans[k++] = nums[i++];
        }
        else
        {
            ans[k++] = nums[j++];
        }
    }
    while (i <= mid)
    {
        ans[k++] = nums[i++];
    }
    while (j <= en)
    {
        ans[k++] = nums[j++];
    }

    for (int i = st; i <= en; i++)
    {
        nums[i] = ans[i];
    }
}

void mergeSort(int nums[], int st, int en)
{
    if (st < en)
    {
        int mid = (st + en) / 2;

        mergeSort(nums, st, mid);
        mergeSort(nums, mid + 1, en);

        merge(nums, st, mid, en);
    }
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

    mergeSort(nums, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
