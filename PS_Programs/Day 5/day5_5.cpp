#include <bits/stdc++.h>
using namespace std;

void generate(int nums[], int n)
{
    int st, x = 0;

    if (n % 2 == 0)
    {
        st = n;
    }
    else
    {
        st = n - 1;
    }
    
    for (int i = 1; i <= n; i += 2)
    {
        nums[x++] = i;
    }

    for (int i = st; i >= 2; i -= 2)
    {
        nums[x++] = i;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int nums[n];
        generate(nums, n);
        for (int i = 0; i < n; i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
