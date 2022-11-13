#include <bits/stdc++.h>
using namespace std;

bool pallindrome(string ss, int i, int n)
{
    if (i >= n)
    {
        return true;
    }
    else if (ss[i] != ss[n])
    {
        return false;
    }
    return pallindrome(ss, i + 1, n - 1);
}

int main()
{
    string ss;
    cin >> ss;

    cout << pallindrome(ss, 0, ss.length() - 1) << endl;
}
