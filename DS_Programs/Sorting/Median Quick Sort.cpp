#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int nums[], int st, int en)
{
    int pivot = nums[en];
    int i = st - 1;

    for (int j = st; j < en; j++)
    {
        if (nums[j] <= pivot)
        {
            i++;
            swap(&nums[i], &nums[j]);
        }
    }

    swap(&nums[i + 1], &nums[en]);
    return i + 1;
}

void quickSort(int nums[], int st, int en)
{
    if (st < en)
    {
        int pivot = partition(nums, st, en);
        quickSort(nums, st, pivot - 1);
        quickSort(nums, pivot + 1, en);
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

    int mid = n / 2;
    swap(nums[0], nums[mid]);

    quickSort(nums, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
