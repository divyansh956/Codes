#include <bits/stdc++.h>
using namespace std;

int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sum(n - 1);
}

int main()
{
    int n;
    cin >> n;

    cout << sum(n) << endl;
}



/******************************************************************************************/


#include <bits/stdc++.h>
using namespace std;

int sum(int n, int s)
{
    if (n == 0)
    {
        return s;
    }
    sum(n - 1, s + n);
}

int main()
{
    int n;
    cin >> n;

    cout << sum(n, 0) << endl;
}
