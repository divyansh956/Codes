#include <bits/stdc++.h>
using namespace std;

void rotate90acw(int nums[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            swap(nums[i][j], nums[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(nums, nums + n);
    }
}

int main()
{
    int n;
    cin >> n;

    int nums[100][100];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> nums[i][j];
        }
    }

    rotate90acw(nums, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}
