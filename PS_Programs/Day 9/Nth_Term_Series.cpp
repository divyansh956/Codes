#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int nthOfSeries(long long int n)
    {
        return n * (n * 8) + 1;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthOfSeries(n) << endl;
    }
    return 0;
}

