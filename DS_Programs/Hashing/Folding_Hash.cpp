#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

void foldingHash(int ts, ll n)
{
    ts = ts - 1;

    int temp = ts, p = 1;
    int digts = 0;
    ll sum = 0, ans;

    while (ts != 0)
    {
        ts /= 10;
        digts++;
    }

    for (int i = 1; i <= digts; i++)
    {
        p *= 10;
    }

    while (n != 0)
    {
        sum += (n % p);
        n /= p;
    }

    ans = sum % p;
    ans = ans % temp;
    
    cout << ans << endl;
}

int main()
{
    int ts;
    cin >> ts;

    ll n;
    cin >> n;

    foldingHash(ts, n);
}
