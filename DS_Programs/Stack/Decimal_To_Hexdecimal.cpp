#include <bits/stdc++.h>
using namespace std;

void decimalTohexa(int n)
{
    stack<char> s[100];
    while (n != 0)
    {
        char x;
        if (n % 16 >= 10)
        {
            x = n % 16 + 55;
        }
        else
        {
            x = n % 16 + 48;
        }
        s->push(x);
        n = n / 16;
    }

    while (!s->empty())
    {
        cout << s->top();
        s->pop();
    }
}

int main()
{
    int n;
    cin >> n;

    decimalTohexa(n);
}
