#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string ss = to_string(n);
    int idx = ss.length() / 2 + 1;

    int sum = 0;

    for (int i = 0; i < idx - 1; i++)
    {
        sum += (ss[i] - '0');
    }
    for (int i = idx + 1; i < ss.length(); i++)
    {
        sum -= (ss[i] - '0');
    }

    if (sum == 0)
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Unbalanced" << endl;
    }
}
