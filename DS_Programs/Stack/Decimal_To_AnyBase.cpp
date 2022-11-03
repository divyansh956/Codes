#include <bits/stdc++.h>
using namespace std;

void decimalToAny(int n, int x)
{
    stack<char> s[100];
    while (n != 0)
    {
        char c;
        if (n % x >= 10)
        {
            c = n % x + 55;
        }
        else
        {
            c = n % x + 48;
        }
        s->push(c);
        n = n / x;
    }

    while (!s->empty())
    {
        cout << s->top();
        s->pop();
    }
}

int main()
{
    int n, x;
    cin >> n >> x;

    decimalToAny(n,x);
}
