#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

void midsquare(int ts, ll n)
{
    ts = ts - 1;

    int digkey = 0;
    int digts = 0;

    int t = ts;
    ll c = 1, N = 1, sq = 1, temp = n, ans = 1, p = 1, q = 1;

    while (n > 0)
    {
        n = n / 10;
        digkey++;
    }

    while (ts > 0)
    {
        ts = ts / 10;
        digts++;
    }

    sq = temp * temp;
    c = ((2 * digkey) - digts) / 2;

    for (int i = 1; i <= c; i++)
    {
        p *= 10;
    }

    for (int i = 1; i <= digts; i++)
    {
        q *= 10;
    }

    N = sq / p;
    ans = N % q;
    ans = ans % t; 
    
    cout << ans << endl;
}

int main()
{
    int ts;
    cin >> ts;

    ll n;
    cin >> n;

    midsquare(ts, n);
}
