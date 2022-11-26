#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int nums[n];
        int x = n - 1;

        for (int i = 0; i < n; i += 2)
        {
            nums[i] = x--;
        }
        x = 0;
        for (int i = 1; i < n; i += 2)
        {
            nums[i] = x++;
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == k)
            {
                cout << i << endl;
            }
        }
    }
}
