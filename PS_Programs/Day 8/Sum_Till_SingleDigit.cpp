#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string ss = to_string(n);

    while (ss.length() != 1)
    {
        int sum = 0;
        for (int i = 0; i < ss.length(); i++)
        {
            sum += (ss[i] - '0');
        }
        ss = to_string(sum);
    }
    cout << ss[0] << endl;
}
