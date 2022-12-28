#include <bits/stdc++.h>
using namespace std;

void maxHeapify(int nums[], int i, int n)
{
    while (i * 2 <= n)
    {
        int l = i * 2;
        int r = i * 2 + 1;
        int mx = l;

        if (r <= n)
        {
            if (nums[r] > nums[l])
            {
                mx = r;
            }
        }

        if (nums[mx] > nums[i])
        {
            swap(nums[mx], nums[i]);
        }
        else
        {
            break;
        }

        i = mx;
    }
}

void buildMaxHeap(int nums[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        maxHeapify(nums, i, n);
    }
}

void HeapSort(int nums[], int n)
{
    buildMaxHeap(nums, n);

    for (int j = n; j >= 2; j--)
    {
        swap(nums[1], nums[j]);
        maxHeapify(nums, 1, j - 1);
    }
}

int main()
{
    int n;
    cin >> n;

    int nums[n];
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }

    HeapSort(nums, n);

    for (int i = 1; i <= n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
