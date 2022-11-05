#include <bits/stdc++.h>
using namespace std;

void rotate180cw(int nums[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        reverse(nums, nums + n);
    }

    for (int i = 0; i < n; i++)
    {
        reverse(nums[i], nums[i] + n);
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

    rotate180cw(nums, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}
