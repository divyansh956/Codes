#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n, m;
    cin >> n >> m;

    long answer = 0, t;
    t = m;

    while (t--)
    {
        long a, b, k;
        cin >> a >> b >> k;
        answer = answer + (abs(a - b) + 1) * k;
    }

    answer = floor(answer / n);
    cout << answer << endl;
    
    return 0;
}
