#include <bits/stdc++.h>
using namespace std;

void divisionHash(int nums[], int n, int np)
{
    int mod = n % np;
    cout << mod << endl;
}

int nearestPrime(int n)
{
    int DAT[n + 1] = {0};
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (DAT[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                DAT[j] = 1;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (DAT[i] == 0)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;

    int TS;
    cin >> TS;

    int nums[TS];

    int np = nearestPrime(TS);
    divisionHash(nums, n, np);
}
