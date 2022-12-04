#include <bits/stdc++.h>
using namespace std;

void SymmertricDifference(int nums1[], int m, int nums2[], int n)
{
    int ans[m + n];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            ans[k++] = nums1[i++];
        }
        else if (nums1[i] > nums2[j])
        {
            ans[k++] = nums2[j++];
        }
        else
        {
            i++;
            j++;
        }
    }
    while (i < m)
    {
        ans[k++] = nums1[i++];
    }
    while (j < n)
    {
        ans[k++] = nums2[j++];
    }
    cout << "Array After Symmertric Difference :\n";
    for (int i = 0; i < k; i++)
        cout << ans[i] << " ";
    cout << endl;
}

void SetDifference(int nums1[], int m, int nums2[], int n)
{
    int ans[m + n];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            ans[k++] = nums1[i++];
        }
        else if (nums1[i] > nums2[j])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    while (i < m)
    {
        ans[k++] = nums1[i++];
    }
    cout << "Array After Set Difference :\n";
    for (int i = 0; i < k; i++)
        cout << ans[i] << " ";
    cout << endl;
}

void Intersection(int nums1[], int m, int nums2[], int n)
{
    int ans[m + n];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            i++;
        }
        else if (nums1[i] > nums2[j])
        {
            j++;
        }
        else
        {
            ans[k++] = nums1[i++];
            j++;
        }
    }
    cout << "Array After Intersection :\n";
    for (int i = 0; i < k; i++)
        cout << ans[i] << " ";
    cout << endl;
}

void Union(int nums1[], int m, int nums2[], int n)
{
    int ans[m + n];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            ans[k++] = nums1[i++];
        }
        else if (nums1[i] > nums2[j])
        {
            ans[k++] = nums2[j++];
        }
        else
        {
            ans[k++] = nums1[i++];
            j++;
        }
    }
    while (i < m)
    {
        ans[k++] = nums1[i++];
    }
    while (j < n)
    {
        ans[k++] = nums2[j++];
    }
    cout << "Array After Union :\n";
    for (int i = 0; i < k; i++)
        cout << ans[i] << " ";
    cout << endl;
}

void merge(int nums1[], int m, int nums2[], int n)
{
    int ans[m + n];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            ans[k++] = nums1[i++];
        }
        else
        {
            ans[k++] = nums2[j++];
        }
    }
    while (i < m)
    {
        ans[k++] = nums1[i++];
    }
    while (j < n)
    {
        ans[k++] = nums2[j++];
    }
    cout << "Array After Merge :\n";
    for (int i = 0; i < m + n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int nums1[n], nums2[m];

    for (int i = 0; i < n; i++)
    {
        cin >> nums1[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> nums2[i];
    }

    merge(nums1, n, nums2, m);
    Union(nums1, n, nums2, m);
    Intersection(nums1, n, nums2, m);
    SetDifference(nums1, n, nums2, m);
    SymmertricDifference(nums1, n, nums2, m);
}
